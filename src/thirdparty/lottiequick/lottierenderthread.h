#ifndef LOTTIE_QUICK_RENDER_THREAD_H
#define LOTTIE_QUICK_RENDER_THREAD_H

#include <rlottie.h>
#include <QHash>
#include <QMutex>
#include <QSize>
#include <QThread>
#include <QWaitCondition>

namespace LottieQuick {

class LottieAnimation;

class LottieRenderThread : public QThread
{
    Q_OBJECT
    Q_DISABLE_COPY(LottieRenderThread);

    struct Entry
    {
        LottieAnimation *item = nullptr;
        QSize size;
        int frameCount = 0;
        int currentFrame = 0;
        int direction = 1;
        QScopedPointer<rlottie::Animation> animation;
        QHash<int, QImage *> frameCache;
        QList<QImage *> recycledImages;
    };

    LottieRenderThread();

public:
    ~LottieRenderThread() override;

    static LottieRenderThread *instance();

    // Frame is owned by thread and must not be freed
    QImage *getFrame(LottieAnimation *item, int frame);

signals:
    void frameReady(LottieQuick::LottieAnimation *item, int frame);

public slots:
    void registerAnimation(LottieQuick::LottieAnimation *item, rlottie::Animation *lottie);
    void deregisterAnimation(LottieQuick::LottieAnimation *item);
    void setSize(LottieQuick::LottieAnimation *item, QSize size);
    void setCurrentFrame(LottieQuick::LottieAnimation *item, int frame);
    void frameRendered(LottieQuick::LottieAnimation *item, int frame);

protected:
    void run() override;
    void prerender(Entry *entry);

private:
    static LottieRenderThread *m_instance;

    QMutex m_mutex;
    QWaitCondition m_waitCondition;

    int m_cacheSize = 2;
    QHash<LottieAnimation *, Entry *> m_animations;
};

} // namespace LottieQuick

#endif // LOTTIE_QUICK_RENDER_THREAD_H
