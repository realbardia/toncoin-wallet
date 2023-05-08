#include "tontoolkitviewport.h"
#include "tontoolkitviewportcontroller.h"

#include <QtQml>

class TonToolkitViewport::Private
{
public:
    QList<TonToolkitViewportItem*> items;
    QList<TonToolkitViewportItem*> defaultItems;
    QHash<QUrl, QQmlComponent*> components;
};

TonToolkitViewport::TonToolkitViewport(QQuickItem *parent) :
    QQuickItem(parent)
{
    p = new Private;
}

QQmlListProperty<TonToolkitViewportItem> TonToolkitViewport::items()
{
    return QQmlListProperty<TonToolkitViewportItem>(this, &p->items, QQmlListProperty<TonToolkitViewportItem>::AppendFunction(append),
                                                QQmlListProperty<TonToolkitViewportItem>::CountFunction(count),
                                                QQmlListProperty<TonToolkitViewportItem>::AtFunction(at),
                                                QQmlListProperty<TonToolkitViewportItem>::ClearFunction(clear) );
}

QList<TonToolkitViewportItem *> TonToolkitViewport::itemsList() const
{
    return p->items;
}

QStringList TonToolkitViewport::keys() const
{
    QList<TonToolkitViewportItem*> list = p->defaultItems;
    list << p->items;

    QStringList result;
    for (TonToolkitViewportItem *i: list)
        result << i->name().toLower();

    return result;
}

TonToolkitViewportAttechedProperty *TonToolkitViewport::qmlAttachedProperties(QObject *object)
{
    return new TonToolkitViewportAttechedProperty(object);
}

QVariant TonToolkitViewport::getComponent(const QString &name)
{
    QList<TonToolkitViewportItem*> list = p->defaultItems;
    list << p->items;

    for (TonToolkitViewportItem *i: list)
        if (i->name().toLower() == name.toLower())
            return i->component();

    return QVariant();
}

QQmlComponent *TonToolkitViewport::createComponent(const QUrl &url, bool asyn)
{
    QQmlComponent *component = p->components.value(url);
    if (component)
        return component;

    QQmlEngine *engine = qmlEngine(this);
    if (!engine)
    {
        qmlWarning(this) << "Could not find engine of the object";
        return Q_NULLPTR;
    }

    component = new QQmlComponent(engine, url, (asyn? QQmlComponent::Asynchronous : QQmlComponent::PreferSynchronous), this);
    p->components[url] = component;

    connect(component, &QObject::destroyed, this, [this, url](){
        p->components.remove(url);
    });

    return component;
}

void TonToolkitViewport::append(QQmlListProperty<TonToolkitViewportItem> *p, TonToolkitViewportItem *v)
{
    TonToolkitViewport *aobj = static_cast<TonToolkitViewport*>(p->object);
    aobj->p->items.append(v);
    Q_EMIT aobj->itemsChanged();
}

int TonToolkitViewport::count(QQmlListProperty<TonToolkitViewportItem> *p)
{
    TonToolkitViewport *aobj = static_cast<TonToolkitViewport*>(p->object);
    return aobj->p->items.count();
}

TonToolkitViewportItem *TonToolkitViewport::at(QQmlListProperty<TonToolkitViewportItem> *p, int idx)
{
    TonToolkitViewport *aobj = static_cast<TonToolkitViewport*>(p->object);
    return aobj->p->items.at(idx);
}

void TonToolkitViewport::clear(QQmlListProperty<TonToolkitViewportItem> *p)
{
    TonToolkitViewport *aobj = static_cast<TonToolkitViewport*>(p->object);
    aobj->p->items.clear();
    Q_EMIT aobj->itemsChanged();
}

TonToolkitViewport::~TonToolkitViewport()
{
    delete p;
}



TonToolkitViewportAttechedProperty::TonToolkitViewportAttechedProperty(QObject *parent) :
    QObject(parent)
{
}

QObject *TonToolkitViewportAttechedProperty::controller() const
{
    const auto controllers = allControllers();
    if (controllers.isEmpty())
    {
        qmlWarning(this) << "There is no controller attached to the viewport.";
        return Q_NULLPTR;
    }
    return controllers.first();
}

QList<QObject *> TonToolkitViewportAttechedProperty::allControllers() const
{
    QList<QObject*> list;
    for (auto o: TonToolkitViewportController::controllers( TonToolkitViewportAttechedProperty::viewport() ))
        list << o;
    return list;
}

TonToolkitViewport *TonToolkitViewportAttechedProperty::viewport() const
{
    return TonToolkitViewportAttechedProperty::viewport( parent() );
}

TonToolkitViewport *TonToolkitViewportAttechedProperty::viewport(QObject *obj)
{
    TonToolkitViewport *viewport = Q_NULLPTR;
    do
    {
        QQuickItem *item = qobject_cast<QQuickItem*>(obj);
        obj = item? item->parentItem() : obj->parent();

        viewport = qobject_cast<TonToolkitViewport*>(obj);
        if (viewport)
            return viewport;

    } while(obj);

    return viewport;
}

TonToolkitViewportAttechedProperty::~TonToolkitViewportAttechedProperty()
{
}
