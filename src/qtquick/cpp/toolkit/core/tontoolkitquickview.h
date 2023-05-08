#ifndef TONTOOLKITQUICKVIEW_H
#define TONTOOLKITQUICKVIEW_H

#include <QQuickView>
#include <QQmlEngine>
#include <QQuickItem>

class TonToolkitQuickViewPrivate;
class TonToolkitQuickView : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool reverseScroll READ reverseScroll WRITE setReverseScroll NOTIFY reverseScrollChanged)

    Q_PROPERTY(QObject*    root        READ root        WRITE setRoot        NOTIFY rootChanged)

    Q_PROPERTY(QString offlineStoragePath READ offlineStoragePath WRITE setOfflineStoragePath NOTIFY offlineStoragePathChanged)

    Q_PROPERTY(qreal flickVelocity READ flickVelocity NOTIFY fakeSignal)

public:
    TonToolkitQuickView(QQmlEngine *engine, QObject *parent = Q_NULLPTR);
    virtual ~TonToolkitQuickView();

    void setReverseScroll(bool stt);
    bool reverseScroll() const;

    void setRoot( QObject *root );
    QObject *root() const;

    qreal flickVelocity() const;

    void setOfflineStoragePath(const QString &path);
    QString offlineStoragePath() const;

    Q_INVOKABLE void registerWindow(QQuickWindow *window);

Q_SIGNALS:
    void rootChanged();
    void reverseScrollChanged();
    void fakeSignal();
    void closeRequest();
    void offlineStoragePathChanged();

protected:
    bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;

private:
    TonToolkitQuickViewPrivate *p;
};

#endif // TONTOOLKITQUICKVIEW_H
