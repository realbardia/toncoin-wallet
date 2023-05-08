#include "tontoolkitquickview.h"
#include "tontoolkitdevicesitem.h"
#include "tontoolkittoolsitem.h"
#include "tontoolkit_macros.h"
#ifdef Q_OS_ANDROID
#include "tontoolkitjavalayer.h"
#endif

#include <QPointer>
#include <QSharedPointer>
#include <QtQml>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQuickItem>
#include <QScreen>
#include <QSet>
#include <QDebug>

class TonToolkitQuickViewPrivate
{
public:
    QPointer<QObject> root;
    QPointer<QQuickItem> focused_text;

    bool reverseScroll;

    QQmlEngine *engine;
};

TonToolkitQuickView::TonToolkitQuickView(QQmlEngine *engine, QObject *parent ) :
    QObject(parent)
{
    p = new TonToolkitQuickViewPrivate;
    p->engine = engine;
    p->reverseScroll = false;
}

void TonToolkitQuickView::setReverseScroll(bool stt)
{
    if(p->reverseScroll == stt)
        return;

    p->reverseScroll = stt;
    Q_EMIT reverseScrollChanged();
}

bool TonToolkitQuickView::reverseScroll() const
{
    return p->reverseScroll;
}

void TonToolkitQuickView::setRoot(QObject *root)
{
    if( p->root == root )
        return;

    p->root = root;
    Q_EMIT rootChanged();
}

QObject *TonToolkitQuickView::root() const
{
    if( p->root )
        return p->root;

    return p->root;
}

qreal TonToolkitQuickView::flickVelocity() const
{
#ifdef DESKTOP_DEVICE
    return 2500;
#else
    return 25000;
#endif
}

void TonToolkitQuickView::setOfflineStoragePath(const QString &path)
{
    if(path == offlineStoragePath())
        return;

    p->engine->setOfflineStoragePath(path);
    Q_EMIT offlineStoragePathChanged();
}

QString TonToolkitQuickView::offlineStoragePath() const
{
    return p->engine->offlineStoragePath();
}

void TonToolkitQuickView::registerWindow(QQuickWindow *window)
{
#ifdef Q_OS_IOS
    window->setFlag(Qt::MaximizeUsingFullscreenGeometryHint, true);
#endif
    window->installEventFilter(this);
}

bool TonToolkitQuickView::eventFilter(QObject *o, QEvent *e)
{
    QQuickWindow *win = qobject_cast<QQuickWindow*>(o);
    if(win)
    {
        switch( static_cast<int>(e->type()) )
        {
        case QEvent::Close:
            if(o->property("backController").toBool())
            {
                QCloseEvent *ce = static_cast<QCloseEvent*>(e);
                if( o->property("try_close").toBool() || TonToolkitDevices::isDesktop() )
                    ce->accept();
                else
                {
                    ce->ignore();
                    QMetaObject::invokeMethod(o, "closeRequest");
                }
            }
            break;
        case QEvent::KeyPress:
        {
            QKeyEvent *ke = static_cast<QKeyEvent*>(e);
            switch(ke->key())
            {
            case Qt::Key_Escape:
            case Qt::Key_Back:
                QMetaObject::invokeMethod(o, "closeRequest");
                break;
            }
        }
            break;
        }
    }

    return QObject::eventFilter(o,e);
}

TonToolkitQuickView::~TonToolkitQuickView()
{
    delete p;
}
