#ifndef TONTOOLKITVIEWPORT_H
#define TONTOOLKITVIEWPORT_H

#include <QObject>
#include <QQuickItem>

#include "tontoolkitviewportitem.h"

class TonToolkitViewportAttechedProperty;
class TonToolkitViewport : public QQuickItem
{
    Q_OBJECT
    class Private;
    Q_PROPERTY(QQmlListProperty<TonToolkitViewportItem> items READ items NOTIFY itemsChanged)
    Q_PROPERTY(QStringList keys READ keys NOTIFY itemsChanged)

public:
    TonToolkitViewport(QQuickItem *parent = Q_NULLPTR);
    virtual ~TonToolkitViewport();

    QQmlListProperty<TonToolkitViewportItem> items();
    QList<TonToolkitViewportItem*> itemsList() const;
    QStringList keys() const;

    static TonToolkitViewportAttechedProperty *qmlAttachedProperties(QObject *object);

public Q_SLOTS:
    QVariant getComponent(const QString &name);
    QQmlComponent *createComponent(const QUrl &fileUrl, bool asyn = false);

Q_SIGNALS:
    void itemsChanged();
    void viewportChanged();

private:
    static void append(QQmlListProperty<TonToolkitViewportItem> *p, TonToolkitViewportItem *v);
    static int count(QQmlListProperty<TonToolkitViewportItem> *p);
    static TonToolkitViewportItem *at(QQmlListProperty<TonToolkitViewportItem> *p, int idx);
    static void clear(QQmlListProperty<TonToolkitViewportItem> *p);

private:
    Private *p;
};

class TonToolkitViewportController;
class TonToolkitViewportAttechedProperty : public QObject {
    Q_OBJECT
    Q_PROPERTY(QObject* controller READ controller NOTIFY controllersChanged)
    Q_PROPERTY(QList<QObject *> allControllers READ allControllers NOTIFY controllersChanged)
    Q_PROPERTY(TonToolkitViewport* viewport READ viewport NOTIFY controllersChanged)

public:
    TonToolkitViewportAttechedProperty(QObject *parent);
    virtual ~TonToolkitViewportAttechedProperty();

    QObject *controller() const;
    QList<QObject *> allControllers() const;
    TonToolkitViewport *viewport() const;

    static TonToolkitViewport *viewport(QObject *obj);

Q_SIGNALS:
    void controllersChanged();
};

QML_DECLARE_TYPEINFO(TonToolkitViewport, QML_HAS_ATTACHED_PROPERTIES)

#endif // TONTOOLKITVIEWPORT_H
