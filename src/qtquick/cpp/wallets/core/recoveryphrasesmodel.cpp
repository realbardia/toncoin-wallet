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
    auto backend = beginAction();
    if (!backend)
        return;

    const auto pkey = wallet()->publicKey();
    if (pkey.isEmpty())
        return;

    setRefreshing(true);
    backend->exportKey(QByteArray::fromBase64(pkey.toLatin1()), this, [this, pkey](const QStringList &keys, const AbstractWalletBackend::Error &error){
        auto w = wallet();
        if (!w || pkey != w->publicKey())
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

        endAction();
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
