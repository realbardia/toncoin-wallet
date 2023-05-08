#include "recoveryphrasesmodel.h"

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
    setRefreshing(true);

    auto backend = AbstractWalletModel::backend()->backendObject();
    const auto pkey = publicKey();
    backend->exportKey(pkey, [this, pkey](const QStringList &keys, const AbstractWalletBackend::Error &error){
        if (pkey != publicKey())
            return;
        if (error.code)
            setError(error.code, error.message);

        beginResetModel();

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
