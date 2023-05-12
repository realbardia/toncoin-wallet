#include "transactionsmodel.h"
#include "core/tools/crypto.h"

#include <QtQml>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#define CRYPTO_FILE_STORE_SALT "b43a24bb-9382-4b0c-957e-565b8a48d609"

using namespace TON::Wallet;

TransactionsModel::TransactionsModel(QObject *parent) :
    AbstractWalletModel(parent)
{
    mRefreshTimer = new QTimer(this);
    mRefreshTimer->setInterval(100);
    mRefreshTimer->setSingleShot(true);

    connect(mRefreshTimer, &QTimer::timeout, this, &TransactionsModel::tryReload);
}

TransactionsModel::~TransactionsModel()
{
}

QVariant TransactionsModel::data(const QModelIndex &index, int role) const
{
    const auto row = index.row();
    const auto t = mTransactions.at(row);
    switch (role)
    {
    case RoleId:
        return t.id.id;
    case RoleHash:
        return QString::fromLatin1(t.id.hash.toBase64());
    case RoleSource:
        return t.source;
    case RoleDestination:
        return t.destination;
    case RoleValue:
    {
        auto amount = QString::number(t.value);
//        auto dotIdx = amount.indexOf('.');
//        if (dotIdx < 0)
//        {
//            dotIdx = amount.count();
//            amount += '.';
//        }
//        amount = amount.left(dotIdx) + '.' + amount.mid(dotIdx+1).leftJustified(5, '0');
        return amount;
    }
    case RoleDatetime:
        return t.datetime;
    case RoleSection:
        return t.datetime.toString("MMMM dd");
    case RoleFee:
        return t.fee;
    case RoleStorageFee:
        return t.storage_fee;
    case RoleOtherFee:
        return t.other_fee;
    case RoleMessage:
        return t.message;
    case RoleSent:
        return t.sent;
    }

    return QVariant();
}

QHash<qint32, QByteArray> TransactionsModel::roleNames() const
{
    return {
        {RoleId, "id"},
        {RoleHash, "hash"},
        {RoleSource, "source"},
        {RoleDestination, "destination"},
        {RoleValue, "value"},
        {RoleDatetime, "datetime"},
        {RoleSection, "section"},
        {RoleFee, "fee"},
        {RoleStorageFee, "storageFee"},
        {RoleOtherFee, "otherFee"},
        {RoleMessage, "message"},
        {RoleSent, "sent"},
    };
}

int TransactionsModel::count() const
{
    return mTransactions.count();
}

void TransactionsModel::reset()
{
    beginResetModel();
    mTransactions.clear();
    setRefreshing(false);
}

void TransactionsModel::reload()
{
    restore();
    if (mOffsetTransactionHash.isEmpty() || mOffsetTransactionId.isEmpty())
        return;
    if (!AbstractWalletModel::backend())
    {
        qmlWarning(this) << "backend property is null. Please set backend property first.";
        return;
    }

    auto backend = AbstractWalletModel::backend()->backendObject();
    if (!backend)
    {
        qmlWarning(this) << "There is no available backend you selected. Please select another backend.";
        return;
    }

    AbstractWalletBackend::TransactionId transaction;
    transaction.id = mOffsetTransactionId.toLongLong();
    transaction.hash = QByteArray::fromBase64(mOffsetTransactionHash.toLatin1());

    setRefreshing(true);
    const auto pkey = publicKey();
    backend->getTransactions(QByteArray::fromBase64(pkey.toLatin1()), transaction, 100,  [this, pkey](const QList<AbstractWalletBackend::Transaction> &list, const AbstractWalletBackend::Error &error){
        if (pkey != publicKey())
            return;
        if (error.code)
            setError(error.code, error.message);

        beginResetModel();

        mTransactions.clear();
        int count = 1;
        for (const auto &t: list)
        {
            mTransactions << t;
            count++;
        }
        endResetModel();

        store();
        setRefreshing(false);
        Q_EMIT countChanged();
    });
}

void TransactionsModel::store()
{
    if (mCachePath.isEmpty())
        return;

    QFile f(mCachePath);
    if (!f.open(QFile::WriteOnly))
        return;

    QJsonArray array;
    for (const auto &t: mTransactions)
    {
        QJsonObject obj;
        obj["id"] = QString::number(t.id.id);
        obj["hash"] = QString::fromLatin1(t.id.hash.toBase64());
        obj["source"] = t.source;
        obj["destination"] = t.destination;
        obj["value"] = QString::number(t.value);
        obj["datetime"] = QString::number(t.datetime.toSecsSinceEpoch());
        obj["fee"] = QString::number(t.fee);
        obj["storage_fee"] = QString::number(t.storage_fee);
        obj["other_fee"] = QString::number(t.other_fee);
        obj["message"] = t.message;
        obj["sent"] = t.sent;

        array << obj;
    }

    QJsonDocument doc;
    doc.setArray(array);

    const auto data = doc.toJson(QJsonDocument::Compact);
    if (mPassword.isEmpty())
        f.write(data);
    else
    {
        TON::Tools::CryptoAES crypto(CRYPTO_FILE_STORE_SALT + mPassword + CRYPTO_FILE_STORE_SALT);
        f.write( crypto.encrypt(data) );
    }

    f.close();
}

void TransactionsModel::restore()
{
    if (mCachePath.isEmpty())
        return;

    QFile f(mCachePath);
    if (!f.open(QFile::ReadOnly))
        return;

    auto data = f.readAll();
    if (data.isEmpty())
        return;

    if (mPassword.count())
    {
        TON::Tools::CryptoAES crypto(CRYPTO_FILE_STORE_SALT + mPassword + CRYPTO_FILE_STORE_SALT);
        data = crypto.decrypt(data);
    }
    if (data.isEmpty())
        return;

    const auto &json = QJsonDocument::fromJson(data);
    if (json.isEmpty())
        return;

    beginResetModel();
    mTransactions.clear();
    for (const auto &i: json.array())
    {
        const auto obj = i.toObject();
        AbstractWalletBackend::Transaction t;
        t.id.id = obj.value("id").toString().toLongLong();
        t.id.hash = QByteArray::fromBase64(obj.value("hash").toString().toLatin1());
        t.source = obj.value("source").toString();
        t.destination = obj.value("destination").toString();
        t.value = obj.value("value").toString().toDouble();
        t.datetime = QDateTime::fromSecsSinceEpoch(obj.value("datetime").toString().toLongLong());
        t.fee = obj.value("fee").toString().toDouble();
        t.storage_fee = obj.value("storage_fee").toString().toDouble();
        t.other_fee = obj.value("other_fee").toString().toDouble();
        t.message = obj.value("message").toString();
        t.sent = obj.value("sent").toBool();

        mTransactions << t;
    }
    endResetModel();
    f.close();
    Q_EMIT countChanged();
}

QString TransactionsModel::password() const
{
    return mPassword;
}

void TransactionsModel::setPassword(const QString &newPassword)
{
    if (mPassword == newPassword)
        return;
    mPassword = newPassword;
    restore();
    Q_EMIT passwordChanged();
}

QString TransactionsModel::cachePath() const
{
    return mCachePath;
}

void TransactionsModel::setCachePath(const QString &newCachePath)
{
    if (mCachePath == newCachePath)
        return;
    mCachePath = newCachePath;
    restore();
    Q_EMIT cachePathChanged();
}

qint32 TransactionsModel::limit() const
{
    return mLimit;
}

void TransactionsModel::setLimit(qint32 newLimit)
{
    if (mLimit == newLimit)
        return;
    mLimit = newLimit;
    refresh();
    Q_EMIT limitChanged();
}

void TransactionsModel::refresh()
{
    mRefreshTimer->stop();
    mRefreshTimer->start();
}

QString TransactionsModel::offsetTransactionHash() const
{
    return mOffsetTransactionHash;
}

void TransactionsModel::setOffsetTransactionHash(const QString &newOffsetTransactionHash)
{
    if (mOffsetTransactionHash == newOffsetTransactionHash)
        return;
    mOffsetTransactionHash = newOffsetTransactionHash;
    refresh();
    Q_EMIT offsetTransactionHashChanged();
}

QString TransactionsModel::offsetTransactionId() const
{
    return mOffsetTransactionId;
}

void TransactionsModel::setOffsetTransactionId(const QString &newOffsetTransactionId)
{
    if (mOffsetTransactionId == newOffsetTransactionId)
        return;
    mOffsetTransactionId = newOffsetTransactionId;
    refresh();
    Q_EMIT offsetTransactionIdChanged();
}
