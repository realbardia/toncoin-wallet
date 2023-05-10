#ifndef RECOVERYWORDSMODEL_H
#define RECOVERYWORDSMODEL_H

#include "abstractwalletmodel.h"

#include <QPointer>
#include <QTimer>

class RecoveryWordsModel : public AbstractWalletModel
{
    Q_OBJECT
    Q_PROPERTY(QString keyword READ keyword WRITE setKeyword NOTIFY keywordChanged)
    Q_PROPERTY(int total READ total NOTIFY totalChanged)

public:
    enum Roles {
        RoleText = Qt::UserRole,
    };
    Q_ENUM(Roles)

    RecoveryWordsModel(QObject *parent = nullptr);
    virtual ~RecoveryWordsModel();

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    QHash<qint32,QByteArray> roleNames() const Q_DECL_OVERRIDE;

    int count() const Q_DECL_OVERRIDE;
    int total() const;

    QString keyword() const;
    void setKeyword(const QString &newKeyword);

Q_SIGNALS:
    void keywordChanged();
    void totalChanged();

protected:
    void reload() Q_DECL_OVERRIDE;
    void reset() Q_DECL_OVERRIDE;

private:
    struct Phrase {
        QString text;
    };

    QList<Phrase> mPhrases;
    QString mKeyword;
    QTimer *mReloadTimer;
    int mTotal = 0;
};

#endif // RECOVERYWORDSMODEL_H
