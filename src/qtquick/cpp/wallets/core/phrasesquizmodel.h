#ifndef PHRASESQUIZMODEL_H
#define PHRASESQUIZMODEL_H

#include "recoveryphrasesmodel.h"

#include <QPointer>

class PhrasesQuizModel : public RecoveryPhrasesModel
{
    Q_OBJECT
    Q_PROPERTY(int quizLength READ quizLength WRITE setQuizLength NOTIFY quizLengthChanged)
    Q_PROPERTY(QStringList words READ words NOTIFY countChanged)

public:
    PhrasesQuizModel(QObject *parent = nullptr);
    virtual ~PhrasesQuizModel();

    int quizLength() const;
    void setQuizLength(int newQuizLength);

    QStringList words() const;
    Q_INVOKABLE bool test(const QStringList &texts) const;

public Q_SLOTS:
    void refreshQuiz();

Q_SIGNALS:
    void quizLengthChanged();

protected:
    void clearData() Q_DECL_OVERRIDE;
    void reloadData() Q_DECL_OVERRIDE;

    QList<Phrase> modelData() const Q_DECL_OVERRIDE;

private:
    QList<Phrase> mQuiz;
    int mQuizLength = 3;
};

#endif // PHRASESQUIZMODEL_H
