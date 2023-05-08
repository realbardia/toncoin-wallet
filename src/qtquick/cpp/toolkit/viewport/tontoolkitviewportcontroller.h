#ifndef TONTOOLKITVIEWPORTCONTROLLER_H
#define TONTOOLKITVIEWPORTCONTROLLER_H

#include <QObject>
#include <QQmlListProperty>

#include "tontoolkitviewport.h"
#include "tontoolkitviewportcontrollerroute.h"

class TonToolkitViewportController : public QObject
{
    Q_OBJECT
    class Private;
    Q_PROPERTY(QQmlListProperty<TonToolkitViewportControllerRoute> routes READ routes NOTIFY routesChanged)
    Q_PROPERTY(TonToolkitViewport* viewport READ viewport WRITE setViewport NOTIFY viewportChanged)
    Q_PROPERTY(bool allowRecursiveTrigger READ allowRecursiveTrigger WRITE setAllowRecursiveTrigger NOTIFY allowRecursiveTriggerChanged)

    Q_CLASSINFO("DefaultProperty", "routes")

public:
    TonToolkitViewportController(QObject *parent = Q_NULLPTR);
    virtual ~TonToolkitViewportController();

    QQmlListProperty<TonToolkitViewportControllerRoute> routes();

    void setViewport(TonToolkitViewport *viewport);
    TonToolkitViewport *viewport() const;

    bool allowRecursiveTrigger() const;
    void setAllowRecursiveTrigger(bool allowRecursiveTrigger);

    static QList<TonToolkitViewportController *> controllers(TonToolkitViewport *viewport = Q_NULLPTR);

public Q_SLOTS:
    QVariantMap lookup(const QString &url, QVariantMap properties = QVariantMap(), TonToolkitViewport *viewport = Q_NULLPTR);

Q_SIGNALS:
    void routesChanged();
    void viewportChanged();
    void allowRecursiveTriggerChanged();

private:
    static void append(QQmlListProperty<TonToolkitViewportControllerRoute> *p, TonToolkitViewportControllerRoute *v);
    static int count(QQmlListProperty<TonToolkitViewportControllerRoute> *p);
    static TonToolkitViewportControllerRoute *at(QQmlListProperty<TonToolkitViewportControllerRoute> *p, int idx);
    static void clear(QQmlListProperty<TonToolkitViewportControllerRoute> *p);

private:
    Private *p;
};


#endif // TONTOOLKITVIEWPORTCONTROLLER_H
