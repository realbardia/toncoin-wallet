#include "recoveryphrasesmodel.h"

#include <QtQml>

using namespace TON::Wallet;

RecoveryPhrasesModel::RecoveryPhrasesModel(QObject *parent)
    : AbstractWalletModel(parent)
{
}

RecoveryPhrasesModel::~RecoveryPhrasesModel()
{
}

QVariant RecoveryPhrasesModel::data(const QModelIndex &index, int role) const
{
    const auto row = index.row();
    switch (role)
    {
    case RoleText:
        return modelData().at(row).text;
    case RoleItemIndex:
        return modelData().at(row).index;
    }

    return QVariant();
}

QHash<qint32, QByteArray> RecoveryPhrasesModel::roleNames() const
{
    return {
        {RoleText, "text"},
        {RoleItemIndex, "itemIndex"},
    };
}

int RecoveryPhrasesModel::count() const
{
    return modelData().count();
}

void RecoveryPhrasesModel::reload()
{
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

    setRefreshing(true);
    const auto pkey = publicKey();
    backend->exportKey(QByteArray::fromBase64(pkey.toLatin1()), [this, pkey](const QStringList &keys, const AbstractWalletBackend::Error &error){
        if (pkey != publicKey())
            return;
        if (error.code)
            setError(error.code, error.message);

        beginResetModel();

        mPhrases.clear();
        int count = 1;
        for (const auto &text: keys)
        {
            Phrase key = {
                .text = text,
                .index = count,
            };

            mPhrases << key;
            count++;
        }
        reloadData();
        endResetModel();

        setRefreshing(false);
        Q_EMIT countChanged();
    });
}

void RecoveryPhrasesModel::reset()
{
    beginResetModel();
    mPhrases.clear();
    clearData();
    endResetModel();
    setRefreshing(false);
}
