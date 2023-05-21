#ifndef ASEMANSTICKERITEM_H
#define ASEMANSTICKERITEM_H

#include <QQuickItem>

#include "lottieanimation.h"

class AsemanStickerItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(int loops READ loops WRITE setLoops NOTIFY loopsChanged)
    Q_PROPERTY(bool autoPlay READ autoPlay WRITE setAutoPlay NOTIFY autoPlayChanged)

public:
    AsemanStickerItem(QQuickItem *parent = nullptr);
    virtual ~AsemanStickerItem();

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

#endif // ASEMANSTICKERITEM_H
