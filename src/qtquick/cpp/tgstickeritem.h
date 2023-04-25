#ifndef TGSTICKERITEM_H
#define TGSTICKERITEM_H

#include <QQuickItem>

#include "lottiequick/lib/lottieanimation.h"

namespace TON::QML
{

class TgStickerItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(int loops READ loops WRITE setLoops NOTIFY loopsChanged)
    Q_PROPERTY(bool autoPlay READ autoPlay WRITE setAutoPlay NOTIFY autoPlayChanged)

public:
    TgStickerItem(QQuickItem *parent = nullptr);
    virtual ~TgStickerItem();

    QUrl source() const;
    void setSource(const QUrl &newSource);

    int loops() const;
    void setLoops(int newLoops);

    bool autoPlay() const;
    void setAutoPlay(bool newAutoPlay);

public Q_SLOTS:
    void play();
    void pause();

Q_SIGNALS:
    void sourceChanged();
    void loopsChanged();
    void autoPlayChanged();

private:
    LottieQuick::LottieAnimation *mLottieItem = nullptr;
    QUrl mSource;
};

}

#endif // TGSTICKERITEM_H
