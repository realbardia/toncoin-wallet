#include "transactionsmodel.h"

#include <QtQml>

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

        setRefreshing(false);
        Q_EMIT countChanged();
    });
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
