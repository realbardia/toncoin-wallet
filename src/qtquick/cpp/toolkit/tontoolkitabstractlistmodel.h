#ifndef TONTOOLKITABSTRACTLISTMODEL_H
#define TONTOOLKITABSTRACTLISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>

class TonToolkitAbstractListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    TonToolkitAbstractListModel(QObject *parent = Q_NULLPTR);
    virtual ~TonToolkitAbstractListModel();

    Q_INVOKABLE QStringList roles() const;

public Q_SLOTS:
    QVariant get(int index, int role) const;
    QVariant get(int index, const QString &roleName) const;
    QVariantMap get(int index) const;
};

#endif // TONTOOLKITABSTRACTLISTMODEL_H
