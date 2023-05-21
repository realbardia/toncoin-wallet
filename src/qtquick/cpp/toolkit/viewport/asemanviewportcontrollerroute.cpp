#include "asemanviewportcontrollerroute.h"

#include <QQmlContext>

class AsemanViewportControllerRoute::Private
{
public:
    QRegularExpression route;
    QVariant component;
    QString viewportType;
};

AsemanViewportControllerRoute::AsemanViewportControllerRoute(QObject *parent) :
    QObject(parent)
{
    p = new Private;
}

QRegularExpression AsemanViewportControllerRoute::route() const
{
    return p->route;
}

void AsemanViewportControllerRoute::setRoute(const QRegularExpression &route)
{
    if (p->route == route)
        return;

    p->route = route;
    Q_EMIT routeChanged();
}

QVariant AsemanViewportControllerRoute::component() const
{
    return p->component;
}

void AsemanViewportControllerRoute::setComponent(const QVariant &component)
{
    if (p->component == component)
        return;

    p->component = component;
    Q_EMIT componentChanged();
}

QQmlComponent *AsemanViewportControllerRoute::sourceComponent() const
{
    return component().value<QQmlComponent*>();
}

void AsemanViewportControllerRoute::setSourceComponent(QQmlComponent *sourceComponent)
{
    setComponent( QVariant::fromValue(sourceComponent) );
}

QUrl AsemanViewportControllerRoute::source() const
{
    return component().toUrl();
}

void AsemanViewportControllerRoute::setSource(const QUrl &sourceComponent)
{
#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
    const QQmlContext *context = qmlContext(this);
    auto loadUrl = sourceComponent;
    if (context)
        loadUrl = context->resolvedUrl(sourceComponent);

    setComponent( QVariant::fromValue(loadUrl) );
#else
    setComponent( QVariant::fromValue(sourceComponent) );
#endif
}

QString AsemanViewportControllerRoute::viewportType() const
{
    return p->viewportType;
}

void AsemanViewportControllerRoute::setViewportType(const QString &viewportType)
{
    if (p->viewportType == viewportType)
        return;

    p->viewportType = viewportType;
    Q_EMIT viewportTypeChanged();
}

AsemanViewportControllerRoute::~AsemanViewportControllerRoute()
{
    delete p;
}
