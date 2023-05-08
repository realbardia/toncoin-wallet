#ifndef TONTOOLKITQUICKLISTMODEL_H
#define TONTOOLKITQUICKLISTMODEL_H

#include "tontoolkitlistmodel.h"

#include <QQmlListProperty>

class TonToolkitQuickListModel : public TonToolkitListModel
{
    Q_OBJECT
    class Private;

    Q_PROPERTY(QQmlListProperty<QObject> items READ items NOTIFY itemsChanged)
    Q_CLASSINFO("DefaultProperty", "items")

public:
    TonToolkitQuickListModel(QObject *parent = Q_NULLPTR);
    virtual ~TonToolkitQuickListModel();

    QQmlListProperty<QObject> items();
    QList<QObject*> itemsList() const;

Q_SIGNALS:
    void itemsChanged();

private:
    static void append(QQmlListProperty<QObject> *p, QObject *v);
    static int count(QQmlListProperty<QObject> *p);
    static QObject *at(QQmlListProperty<QObject> *p, int idx);
    static void clear(QQmlListProperty<QObject> *p);

private:
    Private *p;
};

#endif // TONTOOLKITQUICKLISTMODEL_H
