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
        return mPhrases.at(row).text;
    }

    return QVariant();
}

QHash<qint32, QByteArray> RecoveryPhrasesModel::roleNames() const
{
    return {
        {RoleText, "text"}
    };
}

int RecoveryPhrasesModel::count() const
{
    return mPhrases.count();
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
        for (const auto &text: keys)
        {
            Phrase key = {
                .text = text,
            };

            mPhrases << key;
        }
        endResetModel();

        setRefreshing(false);
        Q_EMIT countChanged();
    });
}

void RecoveryPhrasesModel::reset()
{
    beginResetModel();
    mPhrases.clear();
    endResetModel();
    setRefreshing(false);
}
