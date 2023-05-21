#include "asemanquicklistmodel.h"

#include <QTimer>
#include <QDebug>

class AsemanQuickListModel::Private
{
public:
    QList<QObject*> items;
};

AsemanQuickListModel::AsemanQuickListModel(QObject *parent) :
    AsemanListModel(parent)
{
    p = new Private;
}

QQmlListProperty<QObject> AsemanQuickListModel::items()
{
    return QQmlListProperty<QObject>(this, &p->items, QQmlListProperty<QObject>::AppendFunction(append),
                                                      QQmlListProperty<QObject>::CountFunction(count),
                                                      QQmlListProperty<QObject>::AtFunction(at),
                                                      QQmlListProperty<QObject>::ClearFunction(clear) );
}

QList<QObject *> AsemanQuickListModel::itemsList() const
{
    return p->items;
}

void AsemanQuickListModel::append(QQmlListProperty<QObject> *p, QObject *v)
{
    AsemanQuickListModel *aobj = static_cast<AsemanQuickListModel*>(p->object);
    aobj->p->items.append(v);
    Q_EMIT aobj->itemsChanged();
}

int AsemanQuickListModel::count(QQmlListProperty<QObject> *p)
{
    AsemanQuickListModel *aobj = static_cast<AsemanQuickListModel*>(p->object);
    return aobj->p->items.count();
}

QObject *AsemanQuickListModel::at(QQmlListProperty<QObject> *p, int idx)
{
    AsemanQuickListModel *aobj = static_cast<AsemanQuickListModel*>(p->object);
    return aobj->p->items.at(idx);
}

void AsemanQuickListModel::clear(QQmlListProperty<QObject> *p)
{
    AsemanQuickListModel *aobj = static_cast<AsemanQuickListModel*>(p->object);
    aobj->p->items.clear();
    Q_EMIT aobj->itemsChanged();
}

AsemanQuickListModel::~AsemanQuickListModel()
{
    delete p;
}
