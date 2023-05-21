#include "asemanquickviewwrapper.h"

AsemanQuickViewWrapper::AsemanQuickViewWrapper(AsemanQuickView *view, QObject *parent) :
    QObject(parent),
    mView(view)
{
    connect(mView, &AsemanQuickView::rootChanged, this, &AsemanQuickViewWrapper::rootChanged);
    connect(mView, &AsemanQuickView::reverseScrollChanged, this, &AsemanQuickViewWrapper::reverseScrollChanged);
    connect(mView, &AsemanQuickView::fakeSignal, this, &AsemanQuickViewWrapper::fakeSignal);
    connect(mView, &AsemanQuickView::closeRequest, this, &AsemanQuickViewWrapper::closeRequest);
    connect(mView, &AsemanQuickView::destroyed, this, &AsemanQuickViewWrapper::viewDestroyed);
    connect(mView, &AsemanQuickView::offlineStoragePathChanged, this, &AsemanQuickViewWrapper::offlineStoragePathChanged);
}

AsemanQuickViewWrapper::~AsemanQuickViewWrapper()
{
}

void AsemanQuickViewWrapper::setReverseScroll(bool stt)
{
    mView->setReverseScroll(stt);
}

bool AsemanQuickViewWrapper::reverseScroll() const
{
    return mView->reverseScroll();
}

void AsemanQuickViewWrapper::setRoot(QObject *root)
{
    mView->setRoot(root);
}

QObject *AsemanQuickViewWrapper::root() const
{
    return mView->root();
}

qreal AsemanQuickViewWrapper::flickVelocity() const
{
    return mView->flickVelocity();
}

QWindow *AsemanQuickViewWrapper::window() const
{
    return 0;
}

void AsemanQuickViewWrapper::setOfflineStoragePath(const QString &path)
{
    mView->setOfflineStoragePath(path);
}

QString AsemanQuickViewWrapper::offlineStoragePath() const
{
    return mView->offlineStoragePath();
}

void AsemanQuickViewWrapper::registerWindow(QQuickWindow *window)
{
    mView->registerWindow(window);
}

void AsemanQuickViewWrapper::viewDestroyed()
{
    deleteLater();
}
