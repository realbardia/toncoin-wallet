#include "lottierenderthread.h"
#include "lottieanimation.h"
#include "qtcompat.h"
#include <QImage>
#include <QMutexLocker>
#include <QtDebug>

namespace LottieQuick {

LottieRenderThread *LottieRenderThread::m_instance = nullptr;

LottieRenderThread::LottieRenderThread()
    : QThread()
{
}

LottieRenderThread::~LottieRenderThread()
{
    for (Entry *entry : qAsConst(m_animations))
        qDeleteAll(entry->recycledImages);
}

LottieRenderThread *LottieRenderThread::instance()
{
    if (m_instance == nullptr)
        m_instance = new LottieRenderThread;

    return m_instance;
}

QImage *LottieRenderThread::getFrame(LottieAnimation *item, int frame)
{
    QMutexLocker lock(&m_mutex);

    if (Entry *entry = m_animations.value(item, nullptr))
        return entry->frameCache.value(frame, nullptr);

    return nullptr;
}

void LottieRenderThread::registerAnimation(LottieAnimation *item, rlottie::Animation *lottie)
{
    QMutexLocker lock(&m_mutex);

    Entry *entry = m_animations.value(item, nullptr);
    if (entry == nullptr) {
        entry = new Entry;
        m_animations[item] = entry;
    }

    entry->item = item;
    entry->size = QSize(item->width(), item->height()) * item->frameScale();
    entry->frameCount = item->frameCount();
    entry->currentFrame = 0;
    entry->direction = item->direction();
    entry->animation.reset(lottie);

    // Flush cache if new source was set for animation
    entry->frameCache.clear();

    m_waitCondition.wakeAll();
}

void LottieRenderThread::deregisterAnimation(LottieAnimation *item)
{
    QMutexLocker lock(&m_mutex);

    if (Entry *entry = m_animations.value(item, nullptr)) {
        entry->animation.reset();
        qDeleteAll(entry->frameCache);
        qDeleteAll(entry->recycledImages);
        m_animations.remove(item);
    }
}

void LottieRenderThread::setSize(LottieAnimation *item, QSize size)
{
    QMutexLocker lock(&m_mutex);

    if (Entry *entry = m_animations.value(item, nullptr))
        entry->size = size;
}

void LottieRenderThread::setCurrentFrame(LottieAnimation *item, int frame)
{
    QMutexLocker lock(&m_mutex);

    if (Entry *entry = m_animations.value(item, nullptr)) {
        entry->frameCache.clear();
        entry->currentFrame = frame;
        entry->direction = item->direction();
        m_waitCondition.wakeAll();
    }
}

void LottieRenderThread::frameRendered(LottieAnimation *item, int frame)
{
    QMutexLocker lock(&m_mutex);

    if (Entry *entry = m_animations.value(item, nullptr)) {
        QImage *image = entry->frameCache.take(frame);
        if (image != nullptr) {
            entry->recycledImages.append(image);
            m_waitCondition.wakeAll();
        }
    }
}

void LottieRenderThread::run()
{
    while (!isInterruptionRequested()) {
        QMutexLocker lock(&m_mutex);

        for (Entry *entry : qAsConst(m_animations))
            prerender(entry);

        m_waitCondition.wait(&m_mutex);
    }
}

void LottieRenderThread::prerender(Entry *entry)
{
    while (entry->frameCache.size() < m_cacheSize) {
        QImage *&image = entry->frameCache[entry->currentFrame];

        if (image == nullptr) {
            // Try to recycle image from previous frames to prevent
            // allocations if size was not changed.
            while (!entry->recycledImages.isEmpty()) {
                auto recycledImage = entry->recycledImages.takeFirst();
                if (recycledImage->size() == entry->size) {
                    image = recycledImage;
                } else {
                    delete recycledImage;
                }
            }

            // No recyclable images were found, allocate new.
            if (image == nullptr)
                image = new QImage(entry->size, QImage::Format_ARGB32_Premultiplied);
        }

        rlottie::Surface surface(reinterpret_cast<uint32_t *>(image->bits()),
                                 image->width(),
                                 image->height(),
                                 image->bytesPerLine());

        entry->animation->renderSync(entry->currentFrame, surface);
        emit frameReady(entry->item, entry->currentFrame);

        entry->currentFrame += entry->direction;

        if (entry->currentFrame >= entry->frameCount) {
            entry->currentFrame = 0;
        } else if (entry->currentFrame < 0) {
            entry->currentFrame = entry->frameCount - 1;
        }
    }
}

} // namespace LottieQuick
