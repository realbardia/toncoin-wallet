#include "tgstickeritem.h"
#include "core/tools/ziptools.h"

#include <QCryptographicHash>
#include <QDir>
#include <QDebug>

using namespace TON::QML;

TgStickerItem::TgStickerItem(QQuickItem *parent)
    : QQuickItem(parent)
{
    mLottieItem = new LottieQuick::LottieAnimation(this);
    mLottieItem->setProperty("loops", -1);

    connect(this, &QQuickItem::widthChanged, this, [this](){ mLottieItem->setWidth(width()); });
    connect(this, &QQuickItem::heightChanged, this, [this](){ mLottieItem->setHeight(height()); });

    connect(mLottieItem, &LottieQuick::LottieAnimation::loopsChanged, this, &TgStickerItem::loopsChanged);
    connect(mLottieItem, &LottieQuick::LottieAnimation::autoPlayChanged, this, &TgStickerItem::autoPlayChanged);
}

TgStickerItem::~TgStickerItem()
{
}

QUrl TgStickerItem::source() const
{
    return mSource;
}

void TgStickerItem::setSource(const QUrl &newSource)
{
    if (mSource == newSource)
        return;

    mSource = newSource;

    const auto dest = QDir::tempPath() + '/' + QCryptographicHash::hash(mSource.toString().toUtf8(), QCryptographicHash::Md5).toHex();
    Tools::ZipTools::uncompress(mSource.toString(), dest);

    mLottieItem->setSource(QUrl::fromLocalFile(dest));

    Q_EMIT sourceChanged();
}

int TgStickerItem::loops() const
{
    return mLottieItem->property("loops").toInt();
}

void TgStickerItem::setLoops(int newLoops)
{
    mLottieItem->setProperty("loops", newLoops);
}

bool TgStickerItem::autoPlay() const
{
    return mLottieItem->property("autoPlay").toBool();
}

void TgStickerItem::setAutoPlay(bool newAutoPlay)
{
    mLottieItem->setProperty("autoPlay", newAutoPlay);
}

void TgStickerItem::play()
{
    mLottieItem->play();
}

void TgStickerItem::pause()
{
    mLottieItem->pause();
}
