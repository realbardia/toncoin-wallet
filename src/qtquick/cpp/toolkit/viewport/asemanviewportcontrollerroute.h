#ifndef ASEMANVIEWPORTCONTROLLERROUTE_H
#define ASEMANVIEWPORTCONTROLLERROUTE_H

#include <QObject>
#include <QVariant>
#include <QUrl>
#include <QQmlComponent>
#include <QRegularExpression>

class AsemanViewportControllerRoute : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QRegularExpression route READ route WRITE setRoute NOTIFY routeChanged)
    Q_PROPERTY(QQmlComponent* sourceComponent READ sourceComponent WRITE setSourceComponent NOTIFY componentChanged)
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY componentChanged)
    Q_PROPERTY(QString viewportType READ viewportType WRITE setViewportType NOTIFY viewportTypeChanged)
    Q_CLASSINFO("DefaultProperty", "sourceComponent")

    class Private;

public:
    AsemanViewportControllerRoute(QObject *parent = Q_NULLPTR);
    virtual ~AsemanViewportControllerRoute();

    QRegularExpression route() const;
    void setRoute(const QRegularExpression &route);

    QVariant component() const;
    void setComponent(const QVariant &component);

    QQmlComponent *sourceComponent() const;
    void setSourceComponent(QQmlComponent *sourceComponent);

    QUrl source() const;
    void setSource(const QUrl &sourceComponent);

    QString viewportType() const;
    void setViewportType(const QString &viewportType);

Q_SIGNALS:
    void routeChanged();
    void componentChanged();
    void viewportTypeChanged();

private:
    Private *p;
};

#endif // ASEMANVIEWPORTCONTROLLERROUTE_H
