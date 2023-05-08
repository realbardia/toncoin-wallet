#include "tontoolkitabstractviewporttype.h"
#include "tontoolkitviewport.h"

#include <QPointer>

class TonToolkitAbstractViewportType::Private
{
public:
    QPointer<QQuickItem> foregroundItem;
    QPointer<QQuickItem> backgroundItem;
    QPointer<TonToolkitViewport> viewport;
    QPointer<TonToolkitViewportTypeAttechedProperty> foregroundAttachedType;
    bool open;
};

TonToolkitAbstractViewportType::TonToolkitAbstractViewportType(QQuickItem *parent) :
    QQuickItem(parent)
{
    p = new Private;
    p->open = false;
}

QQuickItem *TonToolkitAbstractViewportType::foregroundItem() const
{
    return p->foregroundItem;
}

void TonToolkitAbstractViewportType::setForegroundItem(QQuickItem *foregroundItem)
{
    if (p->foregroundItem == foregroundItem)
        return;

    if (p->foregroundAttachedType)
    {
        disconnect(p->foregroundAttachedType, &TonToolkitViewportTypeAttechedProperty::gestureWidthChanged, this, &TonToolkitAbstractViewportType::gestureWidthChanged);
        disconnect(p->foregroundAttachedType, &TonToolkitViewportTypeAttechedProperty::maximumWidthChanged, this, &TonToolkitAbstractViewportType::maximumWidthChanged);
        disconnect(p->foregroundAttachedType, &TonToolkitViewportTypeAttechedProperty::touchToCloseChanged, this, &TonToolkitAbstractViewportType::touchToCloseChanged);
        disconnect(p->foregroundAttachedType, &TonToolkitViewportTypeAttechedProperty::blockBackChanged, this, &TonToolkitAbstractViewportType::blockBackChanged);
        disconnect(p->foregroundAttachedType, &TonToolkitViewportTypeAttechedProperty::typeTransformOriginChanged, this, &TonToolkitAbstractViewportType::typeTransformOriginChanged);
        disconnect(p->foregroundAttachedType, &TonToolkitViewportTypeAttechedProperty::openChanged, this, &TonToolkitAbstractViewportType::openChanged);
        disconnect(p->foregroundAttachedType, &TonToolkitViewportTypeAttechedProperty::sourceObjectChanged, this, &TonToolkitAbstractViewportType::sourceObjectChanged);
    }

    p->foregroundItem = foregroundItem;
    p->foregroundAttachedType = qobject_cast<TonToolkitViewportTypeAttechedProperty*>(qmlAttachedPropertiesObject<TonToolkitViewportType>(foregroundItem));

    if (p->foregroundAttachedType)
    {
        connect(p->foregroundAttachedType, &TonToolkitViewportTypeAttechedProperty::gestureWidthChanged, this, &TonToolkitAbstractViewportType::gestureWidthChanged);
        connect(p->foregroundAttachedType, &TonToolkitViewportTypeAttechedProperty::maximumWidthChanged, this, &TonToolkitAbstractViewportType::maximumWidthChanged);
        connect(p->foregroundAttachedType, &TonToolkitViewportTypeAttechedProperty::touchToCloseChanged, this, &TonToolkitAbstractViewportType::touchToCloseChanged);
        connect(p->foregroundAttachedType, &TonToolkitViewportTypeAttechedProperty::blockBackChanged, this, &TonToolkitAbstractViewportType::blockBackChanged);
        connect(p->foregroundAttachedType, &TonToolkitViewportTypeAttechedProperty::typeTransformOriginChanged, this, &TonToolkitAbstractViewportType::typeTransformOriginChanged);
        connect(p->foregroundAttachedType, &TonToolkitViewportTypeAttechedProperty::openChanged, this, &TonToolkitAbstractViewportType::openChanged);
        connect(p->foregroundAttachedType, &TonToolkitViewportTypeAttechedProperty::sourceObjectChanged, this, &TonToolkitAbstractViewportType::sourceObjectChanged);
    }

    Q_EMIT foregroundItemChanged();
    Q_EMIT gestureWidthChanged();
    Q_EMIT maximumWidthChanged();
    Q_EMIT touchToCloseChanged();
    Q_EMIT openChanged();
    Q_EMIT blockBackChanged();
    Q_EMIT typeTransformOriginChanged();
    Q_EMIT sourceObjectChanged();
}

QQuickItem *TonToolkitAbstractViewportType::backgroundItem() const
{
    return p->backgroundItem;
}

void TonToolkitAbstractViewportType::setBackgroundItem(QQuickItem *backgroundItem)
{
    if (p->backgroundItem == backgroundItem)
        return;

    p->backgroundItem = backgroundItem;
    Q_EMIT backgroundItemChanged();
}

TonToolkitViewport *TonToolkitAbstractViewportType::viewport() const
{
    return p->viewport;
}

void TonToolkitAbstractViewportType::setViewport(TonToolkitViewport *viewport)
{
    if (p->viewport == viewport)
        return;

    p->viewport = viewport;
    Q_EMIT viewportChanged();
}

qreal TonToolkitAbstractViewportType::gestureWidth() const
{
    return p->foregroundAttachedType? p->foregroundAttachedType->gestureWidth() : 0;
}

bool TonToolkitAbstractViewportType::gestureWidthIsNull() const
{
    if (!p->foregroundAttachedType)
        return false;

    bool isNull;
    p->foregroundAttachedType->gestureWidth(&isNull);
    return isNull;
}

void TonToolkitAbstractViewportType::setGestureWidth(qreal gestureWidth)
{
    if (!p->foregroundAttachedType)
        return;

    p->foregroundAttachedType->setGestureWidth(gestureWidth);
}

qreal TonToolkitAbstractViewportType::maximumWidth() const
{
    return p->foregroundAttachedType? p->foregroundAttachedType->maximumWidth() : 0;
}

bool TonToolkitAbstractViewportType::maximumWidthIsNull() const
{
    if (!p->foregroundAttachedType)
        return false;

    bool isNull;
    p->foregroundAttachedType->maximumWidth(&isNull);
    return isNull;
}

void TonToolkitAbstractViewportType::setMaximumWidth(qreal maximumWidth)
{
    if (!p->foregroundAttachedType)
        return;

    p->foregroundAttachedType->setMaximumWidth(maximumWidth);
}

QPointF TonToolkitAbstractViewportType::typeTransformOrigin() const
{
    return p->foregroundAttachedType? p->foregroundAttachedType->typeTransformOrigin() : QPointF();
}

bool TonToolkitAbstractViewportType::typeTransformOriginIsNull() const
{
    if (!p->foregroundAttachedType)
        return false;

    bool isNull;
    p->foregroundAttachedType->typeTransformOrigin(&isNull);
    return isNull;
}

void TonToolkitAbstractViewportType::setTypeTransformOrigin(const QPointF &typeTransformOrigin)
{
    if (!p->foregroundAttachedType)
        return;

    p->foregroundAttachedType->setTypeTransformOrigin(typeTransformOrigin);
}

bool TonToolkitAbstractViewportType::touchToClose() const
{
    return p->foregroundAttachedType? p->foregroundAttachedType->touchToClose() : false;
}

bool TonToolkitAbstractViewportType::touchToCloseIsNull() const
{
    if (!p->foregroundAttachedType)
        return false;

    bool isNull;
    p->foregroundAttachedType->touchToClose(&isNull);
    return isNull;
}

void TonToolkitAbstractViewportType::setTouchToClose(bool touchToClose)
{
    if (!p->foregroundAttachedType)
        return;

    p->foregroundAttachedType->setTouchToClose(touchToClose);
}

bool TonToolkitAbstractViewportType::blockBack() const
{
    return p->foregroundAttachedType? p->foregroundAttachedType->blockBack() : false;
}

bool TonToolkitAbstractViewportType::blockBackIsNull() const
{
    if (!p->foregroundAttachedType)
        return false;

    bool isNull;
    p->foregroundAttachedType->blockBack(&isNull);
    return isNull;
}

void TonToolkitAbstractViewportType::setBlockBack(bool blockBack)
{
    if (!p->foregroundAttachedType)
        return;

    p->foregroundAttachedType->setBlockBack(blockBack);
}

QQuickItem *TonToolkitAbstractViewportType::sourceObject() const
{
    return p->foregroundAttachedType? p->foregroundAttachedType->sourceObject() : Q_NULLPTR;
}

bool TonToolkitAbstractViewportType::sourceObjectIsNull() const
{
    if (!p->foregroundAttachedType)
        return false;

    bool isNull;
    p->foregroundAttachedType->sourceObject(&isNull);
    return isNull;
}

void TonToolkitAbstractViewportType::setSourceObject(QQuickItem *item)
{
    if (!p->foregroundAttachedType)
        return;

    p->foregroundAttachedType->setSourceObject(item);
}

bool TonToolkitAbstractViewportType::open() const
{
    return p->foregroundAttachedType? p->foregroundAttachedType->open() : p->open;
}

void TonToolkitAbstractViewportType::setOpen(bool open)
{
    if (p->foregroundAttachedType)
        p->foregroundAttachedType->setOpen(open);

    if (p->open == open)
        return;

    p->open = open;
    Q_EMIT openChanged();
}

TonToolkitAbstractViewportType::~TonToolkitAbstractViewportType()
{
    delete p;
}

TonToolkitViewportTypeAttechedProperty *TonToolkitViewportType::qmlAttachedProperties(QObject *object)
{
    return new TonToolkitViewportTypeAttechedProperty(object);
}

TonToolkitViewportTypeAttechedProperty::TonToolkitViewportTypeAttechedProperty(QObject *parent) :
    QObject(parent),
    mSourceObject(Q_NULLPTR),
    mOpen(true)
{
}

qreal TonToolkitViewportTypeAttechedProperty::gestureWidth(bool *isNull) const
{
    if (isNull) *isNull = mGestureWidth.isNull();
    return mGestureWidth.toReal();
}

void TonToolkitViewportTypeAttechedProperty::setGestureWidth(qreal gestureWidth)
{
    if (mGestureWidth == gestureWidth)
        return;

    mGestureWidth = gestureWidth;
    Q_EMIT gestureWidthChanged();
}

qreal TonToolkitViewportTypeAttechedProperty::maximumWidth(bool *isNull) const
{
    if (isNull) *isNull = mMaximumWidth.isNull();
    return mMaximumWidth.toReal();

}

void TonToolkitViewportTypeAttechedProperty::setMaximumWidth(qreal maximumWidth)
{
    if (mMaximumWidth == maximumWidth)
        return;

    mMaximumWidth = maximumWidth;
    Q_EMIT maximumWidthChanged();
}

QPointF TonToolkitViewportTypeAttechedProperty::typeTransformOrigin(bool *isNull) const
{
    if (isNull) *isNull = mTypeTransformOrigin.isNull();
    return mTypeTransformOrigin;
}

void TonToolkitViewportTypeAttechedProperty::setTypeTransformOrigin(const QPointF &typeTransformOrigin)
{
    if (mTypeTransformOrigin == typeTransformOrigin)
        return;

    mTypeTransformOrigin = typeTransformOrigin;
    Q_EMIT typeTransformOriginChanged();
}

bool TonToolkitViewportTypeAttechedProperty::touchToClose(bool *isNull) const
{
    if (isNull) *isNull = mTouchToClose.isNull();
    return mTouchToClose.toBool();
}

void TonToolkitViewportTypeAttechedProperty::setTouchToClose(bool touchToClose)
{
    if (mTouchToClose == touchToClose)
        return;

    mTouchToClose = touchToClose;
    Q_EMIT touchToCloseChanged();
}

bool TonToolkitViewportTypeAttechedProperty::blockBack(bool *isNull) const
{
    if (isNull) *isNull = mBlockBack.isNull();
    return mBlockBack.toBool();
}

void TonToolkitViewportTypeAttechedProperty::setBlockBack(bool blockBack)
{
    if (mBlockBack == blockBack)
        return;

    mBlockBack = blockBack;
    Q_EMIT blockBackChanged();
}

QQuickItem *TonToolkitViewportTypeAttechedProperty::sourceObject(bool *isNull) const
{
    if (isNull) *isNull = mSourceObject.isNull();
    return mSourceObject;

}

void TonToolkitViewportTypeAttechedProperty::setSourceObject(QQuickItem *item)
{
    if (mSourceObject == item)
        return;

    mSourceObject = item;
    Q_EMIT sourceObjectChanged();
}

bool TonToolkitViewportTypeAttechedProperty::open() const
{
    return mOpen;
}

void TonToolkitViewportTypeAttechedProperty::setOpen(bool open)
{
    if (mOpen == open)
        return;

    mOpen = open;
    Q_EMIT openChanged();
}

TonToolkitViewportTypeAttechedProperty::~TonToolkitViewportTypeAttechedProperty()
{
}
