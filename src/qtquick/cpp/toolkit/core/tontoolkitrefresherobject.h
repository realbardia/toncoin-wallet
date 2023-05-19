#ifndef TONTOOLKITREFRESHEROBJECT_H
#define TONTOOLKITREFRESHEROBJECT_H

#include <QObject>
#include <QTimer>

class TonToolkitRefresherObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool refreshing READ refreshing NOTIFY refreshingChanged)
    Q_PROPERTY(qint32 delay READ delay NOTIFY delayChanged)

public:
    TonToolkitRefresherObject(QObject *parent = nullptr);
    virtual ~TonToolkitRefresherObject();

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

#endif // TONTOOLKITREFRESHEROBJECT_H
