#include "tontoolkitkeyhandler.h"

#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QPointer>

class TonToolkitKeyHandler::Private
{
public:
    QPointer<QObject> window;
    qint32 key;
    qint32 scanCode;
    qint32 modifiers;
    QPointF mousePosition;
    qint32 mouseKey;
};

TonToolkitKeyHandler::TonToolkitKeyHandler(QObject *parent) :
    QObject(parent)
{
    p = new Private;
    p->key = 0;
    p->scanCode = 0;
    p->mouseKey = 0;
    p->modifiers = static_cast<qint32>(Qt::NoModifier);
}

void TonToolkitKeyHandler::setWindow(QObject *window)
{
    if(p->window == window)
        return;

    if(p->window)
        p->window->removeEventFilter(this);
    p->window = window;
    if(p->window)
        p->window->installEventFilter(this);

    Q_EMIT windowChanged();
}

QObject *TonToolkitKeyHandler::window() const
{
    return p->window;
}

qint32 TonToolkitKeyHandler::key() const
{
    return p->key;
}

void TonToolkitKeyHandler::setKey(qint32 key)
{
    if(p->key == key)
        return;

    p->key = key;
    Q_EMIT keyChanged();
}

qint32 TonToolkitKeyHandler::modifiers() const
{
    return p->modifiers;
}

qint32 TonToolkitKeyHandler::mouseKey() const
{
    return p->mouseKey;
}

QPointF TonToolkitKeyHandler::mousePosition() const
{
    return p->mousePosition;
}

qint32 TonToolkitKeyHandler::scanCode() const
{
    return p->scanCode;
}

void TonToolkitKeyHandler::setScanCode(qint32 scanCode)
{
    if(p->scanCode == scanCode)
        return;

    p->scanCode = scanCode;
    Q_EMIT scanCodeChanged();
}

void TonToolkitKeyHandler::setModifiers(qint32 modifiers)
{
    if(p->modifiers == modifiers)
        return;

    p->modifiers = modifiers;
    Q_EMIT modifiersChanged();
}

void TonToolkitKeyHandler::setMouseKey(qint32 mouseKey)
{
    if (p->mouseKey == mouseKey)
        return;

    p->mouseKey = mouseKey;
    Q_EMIT mouseKeyChanged();
}

void TonToolkitKeyHandler::setMousePosition(const QPointF &mousePosition)
{
    if (p->mousePosition == mousePosition)
        return;

    p->mousePosition = mousePosition;
    Q_EMIT mousePositionChanged();
}

bool TonToolkitKeyHandler::eventFilter(QObject *watched, QEvent *ev)
{
    if(watched != p->window)
        return QObject::eventFilter(watched, ev);

    switch(static_cast<int>(ev->type()))
    {
    case QEvent::ActivationChange:
    {
        setModifiers(0);
        setKey(0);
        setScanCode(0);
    }
        break;

    case QEvent::KeyPress:
    {
        QKeyEvent *e = static_cast<QKeyEvent*>(ev);
        if(e->isAutoRepeat())
            return QObject::eventFilter(watched, ev);

        qint32 key = e->key();
        quint32 scanCode = e->nativeScanCode();
        switch (key) {
        case Qt::Key_Shift:
        case Qt::Key_Control:
        case Qt::Key_Meta:
            key = 0;
            scanCode = 0;
            break;
        }

        setKey(key);
        setScanCode(static_cast<qint32>(scanCode));
        setModifiers(static_cast<int>(e->modifiers()));
        Q_EMIT pressed(static_cast<int>(e->modifiers()), key, static_cast<qint32>(scanCode));
    }
        break;

    case QEvent::KeyRelease: {
        QKeyEvent *e = static_cast<QKeyEvent*>(ev);
        if(e->isAutoRepeat())
            return QObject::eventFilter(watched, ev);

        qint32 key = e->key();
        quint32 scanCode = e->nativeScanCode();
        switch (key) {
        case Qt::Key_Shift:
        case Qt::Key_Control:
        case Qt::Key_Meta:
            key = 0;
            scanCode = 0;
            break;
        }
        if(key == p->key) {
            setKey(0);
            setScanCode(0);
        }

        setModifiers(static_cast<int>(e->modifiers()));
        Q_EMIT released(static_cast<int>(e->modifiers()), key, static_cast<qint32>(scanCode));
    }
        break;

    case QEvent::MouseButtonPress: {
        QMouseEvent *e = static_cast<QMouseEvent*>(ev);
        setMouseKey(e->buttons());
    }
        break;

    case QEvent::MouseMove: {
        QMouseEvent *e = static_cast<QMouseEvent*>(ev);
        setMousePosition(e->pos());
    }
        break;
    }

    return QObject::eventFilter(watched, ev);
}

TonToolkitKeyHandler::~TonToolkitKeyHandler()
{
    delete p;
}
