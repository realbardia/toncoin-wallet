#ifndef ASEMANBACKHANDLER_H
#define ASEMANBACKHANDLER_H

#include <QObject>
#include <QJSValue>

class AsemanBackHandlerPrivate;
class AsemanBackHandler : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QObject* topHandlerObject READ topHandlerObject NOTIFY topHandlerChanged)
    Q_PROPERTY(QJSValue topHandlerMethod READ topHandlerMethod NOTIFY topHandlerChanged)
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    AsemanBackHandler(QObject *parent = Q_NULLPTR);
    virtual ~AsemanBackHandler();

    QObject *topHandlerObject() const;
    QJSValue topHandlerMethod() const;

    int count();

public Q_SLOTS:
    void pushHandler( QObject *obj, QJSValue jsv );
    void pushDownHandler( QObject *obj, QJSValue jsv );
    void removeHandler( QObject *obj );

    QObject *tryPopHandler();
    QObject *forcePopHandler();
    void clear();

    bool back();

Q_SIGNALS:
    void topHandlerChanged();
    void countChanged();
    void backFinished();

private Q_SLOTS:
    void object_destroyed( QObject *obj );

private:
    void setupObject(QObject *obj);

private:
    AsemanBackHandlerPrivate *p;
};

#endif // ASEMANBACKHANDLER_H
