#ifndef ASEMANQUICKVIEWWRAPPER_H
#define ASEMANQUICKVIEWWRAPPER_H

#include <QObject>
#include "asemanquickview.h"

class AsemanQuickViewWrapper : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool reverseScroll READ reverseScroll WRITE setReverseScroll NOTIFY reverseScrollChanged)

    Q_PROPERTY(QObject*    root        READ root        WRITE setRoot        NOTIFY rootChanged)

    Q_PROPERTY(QString offlineStoragePath READ offlineStoragePath WRITE setOfflineStoragePath NOTIFY offlineStoragePathChanged)

    Q_PROPERTY(qreal flickVelocity READ flickVelocity NOTIFY fakeSignal)
    Q_PROPERTY(QWindow* window READ window NOTIFY fakeSignal)

public:
    AsemanQuickViewWrapper(AsemanQuickView *view, QObject *parent = Q_NULLPTR);
    virtual ~AsemanQuickViewWrapper();

    void setReverseScroll(bool stt);
    bool reverseScroll() const;

    void setRoot( QObject *root );
    QObject *root() const;

    void setBackController(bool stt);
    bool backController() const;

    qreal flickVelocity() const;

    QWindow *window() const;

    void setOfflineStoragePath(const QString &path);
    QString offlineStoragePath() const;

    Q_INVOKABLE void registerWindow(QQuickWindow *window);

Q_SIGNALS:
    void fullscreenChanged();
    void rootChanged();
    void backControllerChanged();
    void reverseScrollChanged();
    void fakeSignal();
    void closeRequest();
    void offlineStoragePathChanged();

private Q_SLOTS:
    void viewDestroyed();

private:
    AsemanQuickView *mView;
};

#endif // ASEMANQUICKVIEWWRAPPER_H
