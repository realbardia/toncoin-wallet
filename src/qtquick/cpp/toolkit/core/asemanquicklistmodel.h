#ifndef ASEMANQUICKLISTMODEL_H
#define ASEMANQUICKLISTMODEL_H

#include "asemanlistmodel.h"

#include <QQmlListProperty>

class AsemanQuickListModel : public AsemanListModel
{
    Q_OBJECT
    class Private;

    Q_PROPERTY(QQmlListProperty<QObject> items READ items NOTIFY itemsChanged)
    Q_CLASSINFO("DefaultProperty", "items")

public:
    AsemanQuickListModel(QObject *parent = Q_NULLPTR);
    virtual ~AsemanQuickListModel();

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

#endif // ASEMANQUICKLISTMODEL_H
