#include "tontoolkitviewportitem.h"

class TonToolkitViewportItem::Private
{
public:
    QString name;
    QVariant component;
};

TonToolkitViewportItem::TonToolkitViewportItem(QObject *parent) :
    QObject(parent)
{
    p = new Private;
}

TonToolkitViewportItem::TonToolkitViewportItem(const QString &name, const QVariant &component, QObject *parent) :
    TonToolkitViewportItem(parent)
{
    p->name = name;
    p->component = component;
}

QString TonToolkitViewportItem::name() const
{
    return p->name;
}

void TonToolkitViewportItem::setName(const QString &name)
{
    if (p->name == name)
        return;

    p->name = name;
    Q_EMIT nameChanged();
}

QVariant TonToolkitViewportItem::component() const
{
    return p->component;
}

void TonToolkitViewportItem::setComponent(const QVariant &component)
{
    if (p->component == component)
        return;

    p->component = component;
    Q_EMIT componentChanged();
}

TonToolkitViewportItem::~TonToolkitViewportItem()
{
    delete p;
}
