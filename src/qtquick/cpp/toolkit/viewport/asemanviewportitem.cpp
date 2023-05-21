#include "asemanviewportitem.h"

class AsemanViewportItem::Private
{
public:
    QString name;
    QVariant component;
};

AsemanViewportItem::AsemanViewportItem(QObject *parent) :
    QObject(parent)
{
    p = new Private;
}

AsemanViewportItem::AsemanViewportItem(const QString &name, const QVariant &component, QObject *parent) :
    AsemanViewportItem(parent)
{
    p->name = name;
    p->component = component;
}

QString AsemanViewportItem::name() const
{
    return p->name;
}

void AsemanViewportItem::setName(const QString &name)
{
    if (p->name == name)
        return;

    p->name = name;
    Q_EMIT nameChanged();
}

QVariant AsemanViewportItem::component() const
{
    return p->component;
}

void AsemanViewportItem::setComponent(const QVariant &component)
{
    if (p->component == component)
        return;

    p->component = component;
    Q_EMIT componentChanged();
}

AsemanViewportItem::~AsemanViewportItem()
{
    delete p;
}
