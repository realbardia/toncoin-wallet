#include "tontoolkitqrcreator.h"
#include "qr/qr_generate.h"

#include "tontoolkittools.h"

#include <QPainter>

TonToolkitQrCreator::TonToolkitQrCreator(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    mReloadTimer = new QTimer(this);
    mReloadTimer->setSingleShot(true);
    mReloadTimer->setInterval(10);

    connect(mReloadTimer, &QTimer::timeout, this, &TonToolkitQrCreator::doReload);
}

TonToolkitQrCreator::~TonToolkitQrCreator()
{
}

QString TonToolkitQrCreator::text() const
{
    return mText;
}

void TonToolkitQrCreator::setText(const QString &newText)
{
    if (mText == newText)
        return;
    mText = newText;
    reload();
    Q_EMIT textChanged();
}

void TonToolkitQrCreator::reload()
{
    mReloadTimer->stop();
    mReloadTimer->start();
}

void TonToolkitQrCreator::doReload()
{
    if (mText.isEmpty())
    {
        mCachedImage = QImage();
        update();
        return;
    }

    const auto data = Qr::Encode(mText);
    mCachedImage = Qr::Generate(data, 20);
    if (mCenterImage.isValid())
    {
        auto replaceSize = Qr::ReplaceSize(data, 20);
        auto replaceImage = QImage(TonToolkitTools::urlToLocalPath(mCenterImage)).scaledToWidth(replaceSize, Qt::SmoothTransformation);
        mCachedImage = Qr::ReplaceCenter(mCachedImage, replaceImage);
    }
    update();
}

qint32 TonToolkitQrCreator::pixels() const
{
    return mPixels;
}

void TonToolkitQrCreator::setPixels(qint32 newPixels)
{
    if (mPixels == newPixels)
        return;
    mPixels = newPixels;
    reload();
    Q_EMIT pixelsChanged();
}

void TonToolkitQrCreator::paint(QPainter *p)
{
    const QRectF rect(0, 0, width(), height());
    p->eraseRect(rect);

    if (!mCachedImage.isNull())
    {
        const auto w = qMin(rect.width(), rect.height());
        if (mCachedImage.width() != w)
        {
            doReload();
            mCachedImage = mCachedImage.scaledToWidth(w, Qt::SmoothTransformation);
        }

        const auto x = (rect.width() - mCachedImage.width()) / 2;
        const auto y = (rect.height() - mCachedImage.height()) / 2;
        p->drawImage(x, y, mCachedImage);
    }
}

QUrl TonToolkitQrCreator::centerImage() const
{
    return mCenterImage;
}

void TonToolkitQrCreator::setCenterImage(const QUrl &newCenterImage)
{
    if (mCenterImage == newCenterImage)
        return;
    mCenterImage = newCenterImage;
    reload();
    Q_EMIT centerImageChanged();
}
