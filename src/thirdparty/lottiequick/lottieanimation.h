#ifndef LOTTIE_QUICK_ANIMATION_H
#define LOTTIE_QUICK_ANIMATION_H

#include "lottiequickglobal.h"
#include <QImage>
#include <QQuickItem>
#include <QScopedPointer>
#include <QTimer>

namespace LottieQuick {

class LottieRenderThread;

class LOTTIE_QUICK_EXPORT LottieAnimation : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(int frameRate READ frameRate WRITE setFrameRate RESET resetFrameRate NOTIFY frameRateChanged)
    Q_PROPERTY(Status status READ status WRITE setStatus NOTIFY statusChanged)
    Q_PROPERTY(bool autoPlay MEMBER m_autoPlay NOTIFY autoPlayChanged)
    Q_PROPERTY(int loops MEMBER m_loops NOTIFY loopsChanged)
    Q_PROPERTY(Direction direction READ direction WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(bool modelCache MEMBER m_modelCache NOTIFY modelCacheChanged)
    Q_PROPERTY(double frameScale READ frameScale WRITE setFrameScale NOTIFY frameScaleChanged)
    // TODO: add QVariant "from" and "to" properties to play animation between
    //  specified frames or markers

public:
    enum Status { Null, Loading, Ready, Error };
    Q_ENUM(Status)

    enum Direction { Forward = 1, Reverse = -1 };
    Q_ENUM(Direction)

    enum LoopCount { Infinite = -1 };
    Q_ENUM(LoopCount)

    explicit LottieAnimation(QQuickItem *parent = nullptr);
    ~LottieAnimation() override;

    Status status() const;

    QUrl source() const;
    void setSource(const QUrl &source);

    int frameRate() const;
    void setFrameRate(int frameRate);
    void resetFrameRate();

    Direction direction() const;
    void setDirection(Direction direction);

    double frameScale() const;
    void setFrameScale(double scale);

    int frameCount() const;

    // XXX: maybe implement stop() instead of start?
    Q_INVOKABLE void start();
    Q_INVOKABLE void play();
    Q_INVOKABLE void pause();
    Q_INVOKABLE void togglePause();

signals:
    void statusChanged();
    void sourceChanged();
    void frameRateChanged();
    void autoPlayChanged();
    void loopsChanged();
    void directionChanged();
    void modelCacheChanged();
    void frameScaleChanged();
    void finished();

protected:
    QSGNode *updatePaintNode(QSGNode *, UpdatePaintNodeData *) override;
#if (QT_VERSION < QT_VERSION_CHECK(6, 0, 0))
    void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry) override;
#else
    void geometryChange(const QRectF &newGeometry, const QRectF &oldGeometry) override;
#endif

    void componentComplete() override;

private slots:
    void renderNextFrame();

private:
    void reset();
    void setStatus(Status status);
    void load();

private:
    LottieRenderThread *m_renderThread;
    QMetaObject::Connection m_waitForFrameConn;

    Status m_status = Null;
    int m_currentFrame = 0;
    int m_frameCount = 0;
    int m_frameRate = 30;
    int m_sourceFrameRate = 0;
    double m_frameScale = 1.0;
    QTimer *m_frameTimer;
    QUrl m_source;

    bool m_autoPlay = true;
    int m_loops = 1;
    int m_currentLoop = 0;
    Direction m_direction = Forward;
    bool m_modelCache = true;
};

} // namespace LottieQuick

Q_DECLARE_METATYPE(LottieQuick::LottieAnimation*)

#endif // LOTTIE_QUICK_ANIMATION_H
