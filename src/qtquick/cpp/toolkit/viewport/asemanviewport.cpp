#include "asemanviewport.h"
#include "asemanviewportcontroller.h"

#include <QtQml>

class AsemanViewport::Private
{
public:
    QList<AsemanViewportItem*> items;
    QList<AsemanViewportItem*> defaultItems;
    QHash<QUrl, QQmlComponent*> components;
};

AsemanViewport::AsemanViewport(QQuickItem *parent) :
    QQuickItem(parent)
{
    p = new Private;
}

QQmlListProperty<AsemanViewportItem> AsemanViewport::items()
{
    return QQmlListProperty<AsemanViewportItem>(this, &p->items, QQmlListProperty<AsemanViewportItem>::AppendFunction(append),
                                                QQmlListProperty<AsemanViewportItem>::CountFunction(count),
                                                QQmlListProperty<AsemanViewportItem>::AtFunction(at),
                                                QQmlListProperty<AsemanViewportItem>::ClearFunction(clear) );
}

QList<AsemanViewportItem *> AsemanViewport::itemsList() const
{
    return p->items;
}

QStringList AsemanViewport::keys() const
{
    QList<AsemanViewportItem*> list = p->defaultItems;
    list << p->items;

    QStringList result;
    for (AsemanViewportItem *i: list)
        result << i->name().toLower();

    return result;
}

AsemanViewportAttechedProperty *AsemanViewport::qmlAttachedProperties(QObject *object)
{
    return new AsemanViewportAttechedProperty(object);
}

QVariant AsemanViewport::getComponent(const QString &name)
{
    QList<AsemanViewportItem*> list = p->defaultItems;
    list << p->items;

    for (AsemanViewportItem *i: list)
        if (i->name().toLower() == name.toLower())
            return i->component();

    return QVariant();
}

QQmlComponent *AsemanViewport::createComponent(const QUrl &url, bool asyn)
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

void AsemanViewport::append(QQmlListProperty<AsemanViewportItem> *p, AsemanViewportItem *v)
{
    AsemanViewport *aobj = static_cast<AsemanViewport*>(p->object);
    aobj->p->items.append(v);
    Q_EMIT aobj->itemsChanged();
}

int AsemanViewport::count(QQmlListProperty<AsemanViewportItem> *p)
{
    AsemanViewport *aobj = static_cast<AsemanViewport*>(p->object);
    return aobj->p->items.count();
}

AsemanViewportItem *AsemanViewport::at(QQmlListProperty<AsemanViewportItem> *p, int idx)
{
    AsemanViewport *aobj = static_cast<AsemanViewport*>(p->object);
    return aobj->p->items.at(idx);
}

void AsemanViewport::clear(QQmlListProperty<AsemanViewportItem> *p)
{
    AsemanViewport *aobj = static_cast<AsemanViewport*>(p->object);
    aobj->p->items.clear();
    Q_EMIT aobj->itemsChanged();
}

AsemanViewport::~AsemanViewport()
{
    delete p;
}



AsemanViewportAttechedProperty::AsemanViewportAttechedProperty(QObject *parent) :
    QObject(parent)
{
}

QObject *AsemanViewportAttechedProperty::controller() const
{
    const auto controllers = allControllers();
    if (controllers.isEmpty())
    {
        qmlWarning(this) << "There is no controller attached to the viewport.";
        return Q_NULLPTR;
    }
    return controllers.first();
}

QList<QObject *> AsemanViewportAttechedProperty::allControllers() const
{
    QList<QObject*> list;
    for (auto o: AsemanViewportController::controllers( AsemanViewportAttechedProperty::viewport() ))
        list << o;
    return list;
}

AsemanViewport *AsemanViewportAttechedProperty::viewport() const
{
    return AsemanViewportAttechedProperty::viewport( parent() );
}

AsemanViewport *AsemanViewportAttechedProperty::viewport(QObject *obj)
{
    AsemanViewport *viewport = Q_NULLPTR;
    do
    {
        QQuickItem *item = qobject_cast<QQuickItem*>(obj);
        obj = item? item->parentItem() : obj->parent();

        viewport = qobject_cast<AsemanViewport*>(obj);
        if (viewport)
            return viewport;

    } while(obj);

    return viewport;
}

AsemanViewportAttechedProperty::~AsemanViewportAttechedProperty()
{
}
