#include "lottieanimation.h"
#include "lottierenderthread.h"
#include <rlottie.h>
#include <sstream>
#ifdef WITH_ZLIB
#include <zlib.h>
#endif
#include <QQuickWindow>
#include <QSGGeometryNode>
#include <QSGSimpleTextureNode>
#include <QtDebug>

Q_DECLARE_METATYPE(rlottie::Animation*)

namespace {

std::string loadFileContent(const QString &path)
{
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open" << path << "for reading";
        return {};
    }

#ifdef WITH_ZLIB
    // Handle gzipped files as well (also known as TGS format, for Telegram stickers)
    char buf[BUFSIZ];
    std::stringstream ss;
    gzFile gzf = gzdopen(file.handle(), "r");

    while (true) {
        int len = gzread(gzf, buf, sizeof(buf));

        if (len < 0) {
            qDebug() << "Failed to read" << path << "content";
            return {};
        }

        ss.write(buf, len);

        if (static_cast<size_t>(len) < sizeof(buf))
            break;
    }

    return ss.str();
#else
    return file.readAll().toStdString();
#endif
}

} // namespace

namespace LottieQuick {

LottieAnimation::LottieAnimation(QQuickItem *parent)
    : QQuickItem(parent)
    , m_renderThread(LottieRenderThread::instance())
    , m_frameTimer(new QTimer(this))
{
    setFlags(ItemHasContents);

    m_frameTimer->setInterval(1000 / m_frameRate);
    m_frameTimer->setSingleShot(false);
    connect(m_frameTimer, &QTimer::timeout, this, &LottieAnimation::renderNextFrame);

    qRegisterMetaType<LottieQuick::LottieAnimation*>();
    qRegisterMetaType<rlottie::Animation*>();
}

LottieAnimation::~LottieAnimation()
{
    QMetaObject::invokeMethod(m_renderThread,
                              "deregisterAnimation",
                              Q_ARG(LottieQuick::LottieAnimation*, this));
}

LottieAnimation::Status LottieAnimation::status() const
{
    return m_status;
}

QUrl LottieAnimation::source() const
{
    return m_source;
}

void LottieAnimation::setSource(const QUrl &source)
{
    if (source == m_source)
        return;

    const auto scheme = source.scheme();

    // TODO: handle not only file:// urls
    if (!scheme.isEmpty() && scheme != QStringLiteral("file"))
        return;

    m_source = source;
    emit sourceChanged();

    if (isComponentComplete())
        load();
}

int LottieAnimation::frameRate() const
{
    return m_frameRate;
}

void LottieAnimation::setFrameRate(int frameRate)
{
    if (frameRate == m_frameRate || frameRate <= 0)
        return;

    m_frameRate = frameRate;
    emit frameRateChanged();

    m_frameTimer->setInterval(1000 / m_frameRate);
}

void LottieAnimation::resetFrameRate()
{
    setFrameRate(m_sourceFrameRate);
}

LottieAnimation::Direction LottieAnimation::direction() const
{
    return m_direction;
}

void LottieAnimation::setDirection(Direction direction)
{
    if (direction == m_direction)
        return;

    m_direction = direction;
    emit directionChanged();

    QMetaObject::invokeMethod(m_renderThread,
                              "setCurrentFrame",
                              Q_ARG(LottieQuick::LottieAnimation*, this),
                              Q_ARG(int, m_currentFrame));
}

double LottieAnimation::frameScale() const
{
    return m_frameScale;
}

void LottieAnimation::setFrameScale(double scale)
{
    if (scale == m_frameScale)
        return;

    m_frameScale = qBound(0.1, scale, 1.0);
    emit scaleChanged();

    auto size = (QSizeF(width(), height()) * m_frameScale).toSize();

    QMetaObject::invokeMethod(m_renderThread,
                              "setSize",
                              Q_ARG(LottieQuick::LottieAnimation*, this),
                              Q_ARG(QSize, size));
}

int LottieAnimation::frameCount() const
{
    return m_frameCount;
}

void LottieAnimation::start()
{
    reset();
    m_frameTimer->start();
}

void LottieAnimation::play()
{
    m_frameTimer->start();
}

void LottieAnimation::pause()
{
    m_frameTimer->stop();
}

void LottieAnimation::togglePause()
{
    if (m_frameTimer->isActive())
        pause();
    else
        play();
}

QSGNode *LottieAnimation::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    auto node = static_cast<QSGSimpleTextureNode *>(oldNode);

    QImage *image = m_renderThread->getFrame(this, m_currentFrame);
    if (image == nullptr) {
        qDebug() << "Got empty frame";
        return node;
    }

    // QSGSimpleTextureNode must be returned with valid texture,
    // so if there is no rendered frame, nullptr must be returned
    // at the beginning of the animation.
    if (node == nullptr)
        node = new QSGSimpleTextureNode();

    auto options = QQuickWindow::TextureHasAlphaChannel;
    auto texture = window()->createTextureFromImage(*image, options);
    node->setRect(boundingRect());
    node->setOwnsTexture(true);
    node->setTexture(texture);

    m_renderThread->frameRendered(this, m_currentFrame);

    m_currentFrame += m_direction;

    if (m_loops > 0 && (m_currentFrame < 0 || m_currentFrame >= m_frameCount))
        m_currentLoop++;

    auto loopsLeft = m_loops - m_currentLoop;
    if (loopsLeft != 0) {
        if (m_currentFrame < 0) {
            m_currentFrame = m_frameCount - 1;
        } else if (m_currentFrame >= m_frameCount) {
            m_currentFrame = 0;
        }
    }

    return node;
}

void LottieAnimation::geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry)
{
    QQuickItem::geometryChanged(newGeometry, oldGeometry);

    if (newGeometry.size().isEmpty())
        return;

    auto size = (newGeometry.size() * m_frameScale).toSize();

    QMetaObject::invokeMethod(m_renderThread,
                              "setSize",
                              Q_ARG(LottieQuick::LottieAnimation*, this),
                              Q_ARG(QSize, size));
}

void LottieAnimation::renderNextFrame()
{
    if (m_currentFrame >= 0 && m_currentFrame < m_frameCount) {
        if (m_renderThread->getFrame(this, m_currentFrame)) {
            update();
        } else if (!m_waitForFrameConn) {
            m_waitForFrameConn = connect(m_renderThread, &LottieRenderThread::frameReady,
                                         this, [=](LottieAnimation *target, int frameNumber) {
                    if (target != this)
                        return;

                    disconnect(m_waitForFrameConn);
                    update();
                });
        }
    } else if (m_loops == m_currentLoop) {
        if (m_loops != -1)
            m_frameTimer->stop();
        emit finished();
    }
}

void LottieAnimation::reset()
{
    m_currentFrame = m_direction == Forward ? 0 : m_frameCount - 1;
    m_currentLoop = 0;
    QMetaObject::invokeMethod(m_renderThread,
                              "setCurrentFrame",
                              Q_ARG(LottieQuick::LottieAnimation*, this),
                              Q_ARG(int, m_currentFrame));
}

void LottieAnimation::setStatus(Status status)
{
    if (status == m_status)
        return;

    m_status = status;
    emit statusChanged();
}

void LottieAnimation::load()
{
    setStatus(Loading);

    std::string data = loadFileContent(m_source.toLocalFile());

    const auto cacheKey = m_source.toString().toStdString();
    auto animation = rlottie::Animation::loadFromData(data, cacheKey, "", m_modelCache);

    if (animation == nullptr) {
        setStatus(Error);
        return;
    }

    size_t width;
    size_t height;
    animation->size(width, height);

    setImplicitWidth(width);
    setImplicitHeight(height);
    m_frameCount = animation->totalFrame();
    m_sourceFrameRate = animation->frameRate();
    setFrameRate(m_sourceFrameRate);

    QMetaObject::invokeMethod(m_renderThread,
                              "registerAnimation",
                              Q_ARG(LottieQuick::LottieAnimation*, this),
                              Q_ARG(rlottie::Animation*, animation.release()));

    if (m_autoPlay)
        start();

    m_renderThread->start();

    setStatus(Ready);
}

void LottieAnimation::componentComplete()
{
    QQuickItem::componentComplete();

    if (m_source.isValid())
        load();
}

} // namespace LottieQuick
