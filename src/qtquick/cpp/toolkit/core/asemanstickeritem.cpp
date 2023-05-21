#include "asemanstickeritem.h"
#include "core/tools/ziptools.h"

#include <QCryptographicHash>
#include <QDir>
#include <QDebug>

#define SCALE 2.0

AsemanStickerItem::AsemanStickerItem(QQuickItem *parent)
    : QQuickItem(parent)
{
    mLottieItem = new LottieQuick::LottieAnimation(this);
    mLottieItem->setProperty("loops", -1);
    mLottieItem->setTransformOrigin(QQuickItem::TopLeft);
    mLottieItem->setScale(1/SCALE);

    connect(this, &QQuickItem::widthChanged, this, [this](){ mLottieItem->setWidth(width()*SCALE); });
    connect(this, &QQuickItem::heightChanged, this, [this](){ mLottieItem->setHeight(height()*SCALE); });

    connect(mLottieItem, &LottieQuick::LottieAnimation::loopsChanged, this, &AsemanStickerItem::loopsChanged);
    connect(mLottieItem, &LottieQuick::LottieAnimation::autoPlayChanged, this, &AsemanStickerItem::autoPlayChanged);
}

AsemanStickerItem::~AsemanStickerItem()
{
}

QUrl AsemanStickerItem::source() const
{
    return mSource;
}

void AsemanStickerItem::setSource(const QUrl &newSource)
{
    if (mSource == newSource)
        return;

    mSource = newSource;

    const auto dest = QDir::tempPath() + '/' + QCryptographicHash::hash(mSource.toString().toUtf8(), QCryptographicHash::Md5).toHex();
    TON::Tools::ZipTools::uncompress(mSource.toString(), dest);

    mLottieItem->setSource(QUrl::fromLocalFile(dest));

    Q_EMIT sourceChanged();
}

int AsemanStickerItem::loops() const
{
    return mLottieItem->property("loops").toInt();
}

void AsemanStickerItem::setLoops(int newLoops)
{
    mLottieItem->setProperty("loops", newLoops);
}

bool AsemanStickerItem::autoPlay() const
{
    return mLottieItem->property("autoPlay").toBool();
}

void AsemanStickerItem::setAutoPlay(bool newAutoPlay)
{
    mLottieItem->setProperty("autoPlay", newAutoPlay);
}

void AsemanStickerItem::play()
{
    mLottieItem->play();
}

void AsemanStickerItem::pause()
{
    mLottieItem->pause();
}
