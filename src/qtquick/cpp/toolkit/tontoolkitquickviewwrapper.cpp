/*
    Copyright (C) 2017 TonToolkit Team
    http://tontoolkit.co

    TonToolkitQtTools is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    TonToolkitQtTools is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
