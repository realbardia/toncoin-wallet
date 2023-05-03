#ifndef TONTOOLKITSTICKERITEM_H
#define TONTOOLKITSTICKERITEM_H

#include <QQuickItem>

#include "lottiequick/lib/lottieanimation.h"

class TonToolkitStickerItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(int loops READ loops WRITE setLoops NOTIFY loopsChanged)
    Q_PROPERTY(bool autoPlay READ autoPlay WRITE setAutoPlay NOTIFY autoPlayChanged)

public:
    TonToolkitStickerItem(QQuickItem *parent = nullptr);
    virtual ~TonToolkitStickerItem();

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

#endif // TONTOOLKITSTICKERITEM_H
