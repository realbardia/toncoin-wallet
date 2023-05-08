#ifndef RECOVERYPHRASESMODEL_H
#define RECOVERYPHRASESMODEL_H

#include "abstractwalletmodel.h"

#include <QPointer>

class RecoveryPhrasesModel : public AbstractWalletModel
{
    Q_OBJECT
public:
    enum Roles {
        RoleText = Qt::UserRole,
        RoleItemIndex,
    };
    Q_ENUM(Roles)

    RecoveryPhrasesModel(QObject *parent = nullptr);
    virtual ~RecoveryPhrasesModel();

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    QHash<qint32,QByteArray> roleNames() const Q_DECL_OVERRIDE;

    int count() const Q_DECL_OVERRIDE;

protected:
    void reload() Q_DECL_OVERRIDE;
    void reset() Q_DECL_OVERRIDE;

    struct Phrase {
        QString text;
        int index;
    };

    virtual void clearData() { mPhrases.clear(); }
    virtual void reloadData() {}
    virtual void phrasesUpdated() {}

    virtual QList<Phrase> modelData() const { return mPhrases; }
    QList<Phrase> phrases() const { return mPhrases; }

private:
    QList<Phrase> mPhrases;
};

#endif // RECOVERYPHRASESMODEL_H
