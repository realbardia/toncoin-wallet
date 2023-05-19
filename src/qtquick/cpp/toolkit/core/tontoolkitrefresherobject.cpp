#include "tontoolkitrefresherobject.h"

TonToolkitRefresherObject::TonToolkitRefresherObject(QObject *parent)
    : QObject(parent)
{
    mDelayTimer = new QTimer(this);
    mDelayTimer->setSingleShot(true);

    connect(mDelayTimer, &QTimer::timeout, this, [this](){
        mRefreshing = true;
        Q_EMIT refreshingChanged();
    });
}

TonToolkitRefresherObject::~TonToolkitRefresherObject()
{
}

bool TonToolkitRefresherObject::refreshing() const
{
    return mRefreshing;
}

bool TonToolkitRefresherObject::active() const
{
    return mDelayTimer->isActive() || mRefreshing;
}

void TonToolkitRefresherObject::setRefreshing(bool state)
{
    if (!state)
    {
        mDelayTimer->stop();
        if (mRefreshing)
            mInitialized = true;

        mRefreshing = false;
        Q_EMIT refreshingChanged();
    }
    else if (!mDelay || !mInitialized)
    {
        mDelayTimer->stop();
        mRefreshing = true;
        Q_EMIT refreshingChanged();
    }
    else
    {
        if (!mDelayTimer->isActive())
            mDelayTimer->start(mDelay);
    }
}

qint32 TonToolkitRefresherObject::delay() const
{
    return mDelay;
}

bool TonToolkitRefresherObject::forceActiveOnInitialize() const
{
    return mForceActiveOnInitialize;
}

void TonToolkitRefresherObject::setForceActiveOnInitialize(bool newForceActiveOnInitialize)
{
    mForceActiveOnInitialize = newForceActiveOnInitialize;
    mInitialized = false;
}

void TonToolkitRefresherObject::setDelay(qint32 newDelay)
{
    if (mDelay == newDelay)
        return;

    mDelay = newDelay;
    if (mDelayTimer->isActive())
    {
        mDelayTimer->stop();
        if (mDelay)
            mDelayTimer->start(mDelay);
        else
        {
            mRefreshing = true;
            Q_EMIT refreshingChanged();
        }
    }

    Q_EMIT delayChanged();
}
