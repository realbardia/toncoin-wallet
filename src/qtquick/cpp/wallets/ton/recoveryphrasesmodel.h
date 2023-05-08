#ifndef RECOVERYPHRASESMODEL_H
#define RECOVERYPHRASESMODEL_H

#include "abstractwalletmodel.h"

#include <QPointer>

class RecoveryPhrasesModel : public AbstractWalletModel
{
    Q_OBJECT
public:
    enum Roles {
        RoleText = Qt::UserRole
    };
    Q_ENUM(Roles)

    RecoveryPhrasesModel(QObject *parent = nullptr);
    virtual ~RecoveryPhrasesModel();

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    QHash<qint32,QByteArray> roleNames() const Q_DECL_OVERRIDE;

    int count() const Q_DECL_OVERRIDE;

protected:
    void reload() Q_DECL_OVERRIDE;
    void reset() Q_DECL_OVERRIDE;

private:
    struct Phrase {
        QString text;
    };

    QList<Phrase> mPhrases;
};

#endif // RECOVERYPHRASESMODEL_H
