#include "tontoolkitquickviewwrapper.h"

TonToolkitQuickViewWrapper::TonToolkitQuickViewWrapper(TonToolkitQuickView *view, QObject *parent) :
    QObject(parent),
    mView(view)
{
    connect(mView, &TonToolkitQuickView::rootChanged, this, &TonToolkitQuickViewWrapper::rootChanged);
    connect(mView, &TonToolkitQuickView::reverseScrollChanged, this, &TonToolkitQuickViewWrapper::reverseScrollChanged);
    connect(mView, &TonToolkitQuickView::fakeSignal, this, &TonToolkitQuickViewWrapper::fakeSignal);
    connect(mView, &TonToolkitQuickView::closeRequest, this, &TonToolkitQuickViewWrapper::closeRequest);
    connect(mView, &TonToolkitQuickView::destroyed, this, &TonToolkitQuickViewWrapper::viewDestroyed);
    connect(mView, &TonToolkitQuickView::offlineStoragePathChanged, this, &TonToolkitQuickViewWrapper::offlineStoragePathChanged);
}

TonToolkitQuickViewWrapper::~TonToolkitQuickViewWrapper()
{
}

void TonToolkitQuickViewWrapper::setReverseScroll(bool stt)
{
    mView->setReverseScroll(stt);
}

bool TonToolkitQuickViewWrapper::reverseScroll() const
{
    return mView->reverseScroll();
}

void TonToolkitQuickViewWrapper::setRoot(QObject *root)
{
    mView->setRoot(root);
}

QObject *TonToolkitQuickViewWrapper::root() const
{
    return mView->root();
}

qreal TonToolkitQuickViewWrapper::flickVelocity() const
{
    return mView->flickVelocity();
}

QWindow *TonToolkitQuickViewWrapper::window() const
{
    return 0;
}

void TonToolkitQuickViewWrapper::setOfflineStoragePath(const QString &path)
{
    mView->setOfflineStoragePath(path);
}

QString TonToolkitQuickViewWrapper::offlineStoragePath() const
{
    return mView->offlineStoragePath();
}

void TonToolkitQuickViewWrapper::registerWindow(QQuickWindow *window)
{
    mView->registerWindow(window);
}

void TonToolkitQuickViewWrapper::viewDestroyed()
{
    deleteLater();
}
