#ifndef TONTOOLKITQRCREATOR_H
#define TONTOOLKITQRCREATOR_H

#include <QQuickPaintedItem>
#include <QUrl>
#include <QImage>
#include <QTimer>

class TonToolkitQrCreator : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QUrl centerImage READ centerImage WRITE setCenterImage NOTIFY centerImageChanged)
    Q_PROPERTY(qint32 pixels READ pixels WRITE setPixels NOTIFY pixelsChanged)

public:
    TonToolkitQrCreator(QQuickItem *parent = nullptr);
    virtual ~TonToolkitQrCreator();

    QString text() const;
    void setText(const QString &newText);

    QUrl centerImage() const;
    void setCenterImage(const QUrl &newCenterImage);

    qint32 pixels() const;
    void setPixels(qint32 newPixels);

    void paint(QPainter *painter);

public Q_SLOTS:
    void reload();

Q_SIGNALS:
    void textChanged();
    void centerImageChanged();
    void pixelsChanged();

protected:
    void doReload();

private:
    QImage mCachedImage;
    QString mText;
    QUrl mCenterImage;
    qint32 mPixels = 20;

    QTimer *mReloadTimer;
};

#endif // TONTOOLKITQRCREATOR_H
