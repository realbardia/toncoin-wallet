#include "transactionsmodel.h"
#include "core/tools/crypto.h"

#include <QtQml>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QRegularExpression>
#include <QUuid>

#define CRYPTO_FILE_STORE_SALT "b43a24bb-9382-4b0c-957e-565b8a48d609"

using namespace TON::Wallet;

TransactionsModel::TransactionsModel(QObject *parent) :
    AbstractWalletModel(parent)
{
    mRefreshTimer = new QTimer(this);
    mRefreshTimer->setInterval(100);
    mRefreshTimer->setSingleShot(true);

    connect(mRefreshTimer, &QTimer::timeout, this, &TransactionsModel::tryReload);

    mPendingTimer = new QTimer(this);
    mPendingTimer->setInterval(10000);
    mPendingTimer->setSingleShot(true);

    connect(mPendingTimer, &QTimer::timeout, this, &TransactionsModel::tryReload);

    mReloadTimer = new QTimer(this);
    mReloadTimer->setInterval(60000);
    mReloadTimer->setSingleShot(true);

    connect(mReloadTimer, &QTimer::timeout, this, &TransactionsModel::tryReload);
}

TransactionsModel::~TransactionsModel()
{
}

QVariant TransactionsModel::data(const QModelIndex &index, int role) const
{
    const auto row = index.row();
    const auto t = mTransactions.at(row);

    static QRegularExpression rx1("0+$");
    static QRegularExpression rx2("(?:\\.)0*$");
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
        return QString::number(t.value, 'f', 9).remove(rx1).remove(rx2);
    case RoleDatetime:
        return t.datetime;
    case RoleSection:
        return t.datetime.toString("MMMM dd");
    case RoleFee:
        return QString::number(t.fee, 'f', 9).remove(rx1).remove(rx2);
    case RoleStorageFee:
        return QString::number(t.storage_fee, 'f', 9).remove(rx1).remove(rx2);
    case RoleOtherFee:
        return QString::number(t.other_fee, 'f', 9).remove(rx1).remove(rx2);
    case RoleMessage:
        return t.message;
    case RoleSent:
        return t.sent;
    case RolePending:
        return t.pending;
    case RoleInitializeWallet:
        return t.initializeWallet;
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
        {RolePending, "pending"},
        {RoleInitializeWallet, "initializeWallet"},
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
    mReloadTimer->stop();
    restore();

    auto backend = beginAction();
    if (!backend)
        return;

    setRefreshing(true);
    const auto pkey = wallet()->publicKey();
    backend->getTransactions(QByteArray::fromBase64(pkey.toLatin1()), AbstractWalletBackend::TransactionId(), 100,  [this, pkey](const QList<AbstractWalletBackend::Transaction> &list, const AbstractWalletBackend::Error &error){
        auto w = wallet();
        if (!w || pkey != w->publicKey())
            return;
        if (error.code)
            setError(error.code, error.message);

        beginResetModel();

        mTransactions.clear();
        QSet<QByteArray> hashes;
        for (const auto &t: list)
        {
            hashes.insert(t.body_hash);
            mTransactions << t;
        }
        for (const auto &t: mPendingTransactions)
        {
            if (hashes.contains(t.body_hash))
                continue;

            mTransactions.prepend(t);
        }
        endResetModel();

        store();
        setRefreshing(false);
        Q_EMIT countChanged();
        mReloadTimer->start();
    });
}

void TransactionsModel::store()
{
    if (mCachePath.isEmpty())
        return;

    QFile f(mCachePath);
    if (!f.open(QFile::WriteOnly))
        return;

    static QRegularExpression rx("0+$");
    QJsonArray array;
    for (const auto &t: mTransactions)
    {
        QJsonObject obj;
        obj["pending"] = t.pending;
        obj["id"] = QString::number(t.id.id);
        obj["hash"] = QString::fromLatin1(t.id.hash.toBase64());
        obj["source"] = t.source;
        obj["destination"] = t.destination;
        obj["value"] = QString::number(t.value, 'f', 9).remove(rx);
        obj["datetime"] = QString::number(t.datetime.toSecsSinceEpoch());
        obj["fee"] = QString::number(t.fee, 'f', 9).remove(rx);
        obj["storage_fee"] = QString::number(t.storage_fee, 'f', 9).remove(rx);
        obj["other_fee"] = QString::number(t.other_fee, 'f', 9).remove(rx);
        obj["message"] = t.message;
        obj["raw_message"] = QString::fromLatin1(t.raw_message.toBase64());
        obj["body_hash"] = QString::fromLatin1(t.body_hash.toBase64());
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
    mPendingTransactions.clear();
    for (const auto &i: json.array())
    {
        const auto obj = i.toObject();
        Transaction t;
        t.pending = obj.value("pending").toBool();
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
        t.raw_message = QByteArray::fromBase64(obj.value("raw_message").toString().toLatin1());
        t.body_hash = QByteArray::fromBase64(obj.value("body_hash").toString().toLatin1());
        t.sent = obj.value("sent").toBool();

        mTransactions << t;
        if (t.pending)
            mPendingTransactions << t;

        startCheckingPending();
    }
    endResetModel();
    f.close();
    Q_EMIT countChanged();
}

void TransactionsModel::startCheckingPending()
{
    mPendingTimer->stop();
    if (mPendingTransactions.count())
        mPendingTimer->start();
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

void TransactionsModel::addPending(TransferRequest *req, FeeEstimater *fee)
{
    const auto total_fee = fee? fee->fee().toDouble() : 0;
    const auto storage_fee = fee? fee->storageFee().toDouble() : 0;
    const auto other_fee = fee? fee->gasFee().toDouble() + fee->fwdFee().toDouble() + fee->inFwdFee().toDouble() : 0;

    connect(req, &TransferRequest::transferFinishedSucessfully, this, [this, total_fee, storage_fee, other_fee, req](const QByteArray &bodyHash){
        auto w = req->wallet();
        if (!w)
            return;

        Transaction t;
        t.id.id = QRandomGenerator::system()->generate64();
        t.id.hash = QCryptographicHash::hash(QUuid::createUuid().toString().toLatin1(), QCryptographicHash::Md5);
        t.pending = true;
        t.destination = req->destinationAddress();
        t.source = w->address();
        t.datetime = QDateTime::currentDateTime();
        t.message = req->message();
        t.value = -1 * req->amount().toDouble();
        t.fee = total_fee;
        t.sent = true;
        t.storage_fee = storage_fee;
        t.other_fee = other_fee;
        t.body_hash = bodyHash;

        mPendingTransactions << t;

        beginInsertRows(QModelIndex(), 0, 1);
        mTransactions.prepend(t);
        endInsertRows();

        store();
        startCheckingPending();
    });
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

void TransactionsModel::more()
{
    return;
    if (refreshing() || mTransactions.isEmpty())
        return;

    auto backend = beginAction();
    if (!backend)
        return;

    setRefreshing(true);
    const auto pkey = wallet()->publicKey();
    backend->getTransactions(QByteArray::fromBase64(pkey.toLatin1()), mTransactions.first().id, 100,  [this, pkey](const QList<AbstractWalletBackend::Transaction> &list, const AbstractWalletBackend::Error &error){
        auto w = wallet();
        if (!w || pkey != w->publicKey())
            return;
        if (error.code)
            setError(error.code, error.message);

        beginInsertRows(QModelIndex(), mTransactions.count(), mTransactions.count() + list.count());

        for (const auto &t: list)
            mTransactions << t;

        endInsertRows();

        store();
        setRefreshing(false);
        Q_EMIT countChanged();
    });
}
