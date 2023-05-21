#ifndef ASEMANVIEWPORTCONTROLLER_H
#define ASEMANVIEWPORTCONTROLLER_H

#include <QObject>
#include <QQmlListProperty>

#include "asemanviewport.h"
#include "asemanviewportcontrollerroute.h"

class AsemanViewportController : public QObject
{
    Q_OBJECT
    class Private;
    Q_PROPERTY(QQmlListProperty<AsemanViewportControllerRoute> routes READ routes NOTIFY routesChanged)
    Q_PROPERTY(AsemanViewport* viewport READ viewport WRITE setViewport NOTIFY viewportChanged)
    Q_PROPERTY(bool allowRecursiveTrigger READ allowRecursiveTrigger WRITE setAllowRecursiveTrigger NOTIFY allowRecursiveTriggerChanged)

    Q_CLASSINFO("DefaultProperty", "routes")

public:
    AsemanViewportController(QObject *parent = Q_NULLPTR);
    virtual ~AsemanViewportController();

    QQmlListProperty<AsemanViewportControllerRoute> routes();

    void setViewport(AsemanViewport *viewport);
    AsemanViewport *viewport() const;

    bool allowRecursiveTrigger() const;
    void setAllowRecursiveTrigger(bool allowRecursiveTrigger);

    static QList<AsemanViewportController *> controllers(AsemanViewport *viewport = Q_NULLPTR);

public Q_SLOTS:
    QVariantMap lookup(const QString &url, QVariantMap properties = QVariantMap(), AsemanViewport *viewport = Q_NULLPTR);

Q_SIGNALS:
    void routesChanged();
    void viewportChanged();
    void allowRecursiveTriggerChanged();

private:
    static void append(QQmlListProperty<AsemanViewportControllerRoute> *p, AsemanViewportControllerRoute *v);
    static int count(QQmlListProperty<AsemanViewportControllerRoute> *p);
    static AsemanViewportControllerRoute *at(QQmlListProperty<AsemanViewportControllerRoute> *p, int idx);
    static void clear(QQmlListProperty<AsemanViewportControllerRoute> *p);

private:
    Private *p;
};


#endif // ASEMANVIEWPORTCONTROLLER_H
