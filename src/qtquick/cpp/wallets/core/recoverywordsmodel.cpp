#include "recoverywordsmodel.h"

#include <QtQml>

using namespace TON::Wallet;

RecoveryWordsModel::RecoveryWordsModel(QObject *parent)
    : AbstractWalletModel(parent)
{
    mReloadTimer = new QTimer(this);
    mReloadTimer->setInterval(100);
    mReloadTimer->setSingleShot(true);

    connect(mReloadTimer, &QTimer::timeout, this, &RecoveryWordsModel::reload);
}

RecoveryWordsModel::~RecoveryWordsModel()
{
}

QVariant RecoveryWordsModel::data(const QModelIndex &index, int role) const
{
    const auto row = index.row();
    switch (role)
    {
    case RoleText:
        return mPhrases.at(row).text;
    }

    return QVariant();
}

QHash<qint32, QByteArray> RecoveryWordsModel::roleNames() const
{
    return {
        {RoleText, "text"},
    };
}

int RecoveryWordsModel::count() const
{
    return mPhrases.count();
}

int RecoveryWordsModel::total() const
{
    return mTotal;
}

void RecoveryWordsModel::reload()
{
    auto backend = beginAction();
    if (!backend)
        return;

    beginResetModel();

    mPhrases.clear();
    auto words = backend->words();
    mTotal = words.count();
    for (int i=0; i<words.count(); i++)
    {
        const auto text = words.at(i);
        if (!mKeyword.isEmpty() && text.left(mKeyword.length()).toLower() != mKeyword.toLower())
            continue;

        Phrase key = {
            .text = text,
        };

        mPhrases << key;
        words.removeAt(i);
        i--;
    }

    if (!mKeyword.isEmpty())
    {
        for (const auto &text: words)
        {
            if (!text.contains(mKeyword, Qt::CaseInsensitive))
                continue;

            Phrase key = {
                .text = text,
            };

            mPhrases << key;
        }
    }
    endResetModel();

    endAction();
    Q_EMIT countChanged();
    Q_EMIT totalChanged();
}

void RecoveryWordsModel::reset()
{
    beginResetModel();
    mPhrases.clear();
    endResetModel();
    setRefreshing(false);
}

QString RecoveryWordsModel::keyword() const
{
    return mKeyword;
}

void RecoveryWordsModel::setKeyword(const QString &newKeyword)
{
    if (mKeyword == newKeyword)
        return;
    mKeyword = newKeyword;
    mReloadTimer->stop();
    mReloadTimer->start();
    Q_EMIT keywordChanged();
}
