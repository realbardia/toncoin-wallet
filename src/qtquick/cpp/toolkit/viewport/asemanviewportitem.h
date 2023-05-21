#ifndef ASEMANVIEWPORTITEM_H
#define ASEMANVIEWPORTITEM_H

#include <QObject>
#include <QVariant>

class AsemanViewportItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QVariant component READ component WRITE setComponent NOTIFY componentChanged)

    class Private;

public:
    AsemanViewportItem(QObject *parent = Q_NULLPTR);
    AsemanViewportItem(const QString &name, const QVariant &component, QObject *parent = Q_NULLPTR);
    virtual ~AsemanViewportItem();

    QString name() const;
    void setName(const QString &name);

    QVariant component() const;
    void setComponent(const QVariant &component);

Q_SIGNALS:
    void nameChanged();
    void componentChanged();

private:
    Private *p;
};

#endif // ASEMANVIEWPORTITEM_H
