#include "tontoolkitviewportcontrollerroute.h"

#include <QQmlContext>

class TonToolkitViewportControllerRoute::Private
{
public:
    QRegularExpression route;
    QVariant component;
    QString viewportType;
};

TonToolkitViewportControllerRoute::TonToolkitViewportControllerRoute(QObject *parent) :
    QObject(parent)
{
    p = new Private;
}

QRegularExpression TonToolkitViewportControllerRoute::route() const
{
    return p->route;
}

void TonToolkitViewportControllerRoute::setRoute(const QRegularExpression &route)
{
    if (p->route == route)
        return;

    p->route = route;
    Q_EMIT routeChanged();
}

QVariant TonToolkitViewportControllerRoute::component() const
{
    return p->component;
}

void TonToolkitViewportControllerRoute::setComponent(const QVariant &component)
{
    if (p->component == component)
        return;

    p->component = component;
    Q_EMIT componentChanged();
}

QQmlComponent *TonToolkitViewportControllerRoute::sourceComponent() const
{
    return component().value<QQmlComponent*>();
}

void TonToolkitViewportControllerRoute::setSourceComponent(QQmlComponent *sourceComponent)
{
    setComponent( QVariant::fromValue(sourceComponent) );
}

QUrl TonToolkitViewportControllerRoute::source() const
{
    return component().toUrl();
}

void TonToolkitViewportControllerRoute::setSource(const QUrl &sourceComponent)
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

QString TonToolkitViewportControllerRoute::viewportType() const
{
    return p->viewportType;
}

void TonToolkitViewportControllerRoute::setViewportType(const QString &viewportType)
{
    if (p->viewportType == viewportType)
        return;

    p->viewportType = viewportType;
    Q_EMIT viewportTypeChanged();
}

TonToolkitViewportControllerRoute::~TonToolkitViewportControllerRoute()
{
    delete p;
}
