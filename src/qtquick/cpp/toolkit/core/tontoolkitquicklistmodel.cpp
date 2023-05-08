#include "tontoolkitquicklistmodel.h"

#include <QTimer>
#include <QDebug>

class TonToolkitQuickListModel::Private
{
public:
    QList<QObject*> items;
};

TonToolkitQuickListModel::TonToolkitQuickListModel(QObject *parent) :
    TonToolkitListModel(parent)
{
    p = new Private;
}

QQmlListProperty<QObject> TonToolkitQuickListModel::items()
{
    return QQmlListProperty<QObject>(this, &p->items, QQmlListProperty<QObject>::AppendFunction(append),
                                                      QQmlListProperty<QObject>::CountFunction(count),
                                                      QQmlListProperty<QObject>::AtFunction(at),
                                                      QQmlListProperty<QObject>::ClearFunction(clear) );
}

QList<QObject *> TonToolkitQuickListModel::itemsList() const
{
    return p->items;
}

void TonToolkitQuickListModel::append(QQmlListProperty<QObject> *p, QObject *v)
{
    TonToolkitQuickListModel *aobj = static_cast<TonToolkitQuickListModel*>(p->object);
    aobj->p->items.append(v);
    Q_EMIT aobj->itemsChanged();
}

int TonToolkitQuickListModel::count(QQmlListProperty<QObject> *p)
{
    TonToolkitQuickListModel *aobj = static_cast<TonToolkitQuickListModel*>(p->object);
    return aobj->p->items.count();
}

QObject *TonToolkitQuickListModel::at(QQmlListProperty<QObject> *p, int idx)
{
    TonToolkitQuickListModel *aobj = static_cast<TonToolkitQuickListModel*>(p->object);
    return aobj->p->items.at(idx);
}

void TonToolkitQuickListModel::clear(QQmlListProperty<QObject> *p)
{
    TonToolkitQuickListModel *aobj = static_cast<TonToolkitQuickListModel*>(p->object);
    aobj->p->items.clear();
    Q_EMIT aobj->itemsChanged();
}

TonToolkitQuickListModel::~TonToolkitQuickListModel()
{
    delete p;
}
