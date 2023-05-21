#ifndef ASEMANREFRESHEROBJECT_H
#define ASEMANREFRESHEROBJECT_H

#include <QObject>
#include <QTimer>

class AsemanRefresherObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool refreshing READ refreshing NOTIFY refreshingChanged)
    Q_PROPERTY(qint32 delay READ delay NOTIFY delayChanged)

public:
    AsemanRefresherObject(QObject *parent = nullptr);
    virtual ~AsemanRefresherObject();

    void setRefreshing(bool state);
    void setDelay(qint32 newDelay);

    bool refreshing() const;
    bool active() const;
    qint32 delay() const;

    bool forceActiveOnInitialize() const;
    void setForceActiveOnInitialize(bool newForceActiveOnInitialize);

Q_SIGNALS:
    void refreshingChanged();
    void delayChanged();

private:
    bool mForceActiveOnInitialize = true;
    bool mInitialized = false;
    bool mRefreshing = false;

    qint32 mDelay = 0;
    QTimer *mDelayTimer;
};

#endif // ASEMANREFRESHEROBJECT_H
