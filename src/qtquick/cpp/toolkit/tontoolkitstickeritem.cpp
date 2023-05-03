#include "tontoolkitstickeritem.h"
#include "core/tools/ziptools.h"

#include <QCryptographicHash>
#include <QDir>
#include <QDebug>

TonToolkitStickerItem::TonToolkitStickerItem(QQuickItem *parent)
    : QQuickItem(parent)
{
    mLottieItem = new LottieQuick::LottieAnimation(this);
    mLottieItem->setProperty("loops", -1);
    mLottieItem->setTransformOrigin(QQuickItem::TopLeft);
    mLottieItem->setScale(0.5);

    connect(this, &QQuickItem::widthChanged, this, [this](){ mLottieItem->setWidth(width()*2); });
    connect(this, &QQuickItem::heightChanged, this, [this](){ mLottieItem->setHeight(height()*2); });

    connect(mLottieItem, &LottieQuick::LottieAnimation::loopsChanged, this, &TonToolkitStickerItem::loopsChanged);
    connect(mLottieItem, &LottieQuick::LottieAnimation::autoPlayChanged, this, &TonToolkitStickerItem::autoPlayChanged);
}

TonToolkitStickerItem::~TonToolkitStickerItem()
{
}

QUrl TonToolkitStickerItem::source() const
{
    return mSource;
}

void TonToolkitStickerItem::setSource(const QUrl &newSource)
{
    if (mSource == newSource)
        return;

    mSource = newSource;

    const auto dest = QDir::tempPath() + '/' + QCryptographicHash::hash(mSource.toString().toUtf8(), QCryptographicHash::Md5).toHex();
    TON::Tools::ZipTools::uncompress(mSource.toString(), dest);

    mLottieItem->setSource(QUrl::fromLocalFile(dest));

    Q_EMIT sourceChanged();
}

int TonToolkitStickerItem::loops() const
{
    return mLottieItem->property("loops").toInt();
}

void TonToolkitStickerItem::setLoops(int newLoops)
{
    mLottieItem->setProperty("loops", newLoops);
}

bool TonToolkitStickerItem::autoPlay() const
{
    return mLottieItem->property("autoPlay").toBool();
}

void TonToolkitStickerItem::setAutoPlay(bool newAutoPlay)
{
    mLottieItem->setProperty("autoPlay", newAutoPlay);
}

void TonToolkitStickerItem::play()
{
    mLottieItem->play();
}

void TonToolkitStickerItem::pause()
{
    mLottieItem->pause();
}
