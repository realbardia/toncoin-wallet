#ifndef ASEMANVIEWPORT_H
#define ASEMANVIEWPORT_H

#include <QObject>
#include <QQuickItem>

#include "asemanviewportitem.h"

class AsemanViewportAttechedProperty;
class AsemanViewport : public QQuickItem
{
    Q_OBJECT
    class Private;
    Q_PROPERTY(QQmlListProperty<AsemanViewportItem> items READ items NOTIFY itemsChanged)
    Q_PROPERTY(QStringList keys READ keys NOTIFY itemsChanged)

public:
    AsemanViewport(QQuickItem *parent = Q_NULLPTR);
    virtual ~AsemanViewport();

    QQmlListProperty<AsemanViewportItem> items();
    QList<AsemanViewportItem*> itemsList() const;
    QStringList keys() const;

    static AsemanViewportAttechedProperty *qmlAttachedProperties(QObject *object);

public Q_SLOTS:
    QVariant getComponent(const QString &name);
    QQmlComponent *createComponent(const QUrl &fileUrl, bool asyn = false);

Q_SIGNALS:
    void itemsChanged();
    void viewportChanged();

private:
    static void append(QQmlListProperty<AsemanViewportItem> *p, AsemanViewportItem *v);
    static int count(QQmlListProperty<AsemanViewportItem> *p);
    static AsemanViewportItem *at(QQmlListProperty<AsemanViewportItem> *p, int idx);
    static void clear(QQmlListProperty<AsemanViewportItem> *p);

private:
    Private *p;
};

class AsemanViewportController;
class AsemanViewportAttechedProperty : public QObject {
    Q_OBJECT
    Q_PROPERTY(QObject* controller READ controller NOTIFY controllersChanged)
    Q_PROPERTY(QList<QObject *> allControllers READ allControllers NOTIFY controllersChanged)
    Q_PROPERTY(AsemanViewport* viewport READ viewport NOTIFY controllersChanged)

public:
    AsemanViewportAttechedProperty(QObject *parent);
    virtual ~AsemanViewportAttechedProperty();

    QObject *controller() const;
    QList<QObject *> allControllers() const;
    AsemanViewport *viewport() const;

    static AsemanViewport *viewport(QObject *obj);

Q_SIGNALS:
    void controllersChanged();
};

QML_DECLARE_TYPEINFO(AsemanViewport, QML_HAS_ATTACHED_PROPERTIES)

#endif // ASEMANVIEWPORT_H
