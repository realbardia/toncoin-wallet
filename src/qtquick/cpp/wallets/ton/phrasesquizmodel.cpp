#include "phrasesquizmodel.h"

#include <QRandomGenerator>

using namespace TON::Wallet;

PhrasesQuizModel::PhrasesQuizModel(QObject *parent)
    : RecoveryPhrasesModel(parent)
{

}

PhrasesQuizModel::~PhrasesQuizModel()
{
}

void PhrasesQuizModel::refreshQuiz()
{
    beginResetModel();
    clearData();
    reloadData();
    endResetModel();
    Q_EMIT countChanged();
}

void PhrasesQuizModel::clearData()
{
    mQuiz.clear();
}

void PhrasesQuizModel::reloadData()
{
    auto phrases = RecoveryPhrasesModel::phrases();

    QMap<int, Phrase> quizMap;
    while (quizMap.count() < mQuizLength && !phrases.isEmpty())
    {
        const auto idx = (QRandomGenerator::system()->generate() % phrases.count());
        auto phrase = phrases.takeAt(idx);
        quizMap[phrase.index] = phrase;
    }

    mQuiz = quizMap.values();
}

QList<RecoveryPhrasesModel::Phrase> PhrasesQuizModel::modelData() const
{
    return mQuiz;
}

int PhrasesQuizModel::quizLength() const
{
    return mQuizLength;
}

void PhrasesQuizModel::setQuizLength(int newQuizLength)
{
    if (mQuizLength == newQuizLength)
        return;
    mQuizLength = newQuizLength;
    refreshQuiz();
    Q_EMIT quizLengthChanged();
}

QStringList PhrasesQuizModel::words() const
{
    QStringList words;
    for (const auto &p: phrases())
        words << p.text;
    return words;
}

bool PhrasesQuizModel::test(const QStringList &texts) const
{
    if (texts.length() != mQuiz.length())
        return false;

    const auto count = mQuiz.count();
    for (int i=0; i<count; i++)
    {
        if (mQuiz.at(i).text != texts.at(i))
            return false;
    }

    return true;
}
