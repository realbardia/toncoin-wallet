#ifndef ASEMANQUICKOBJECT_H
#define ASEMANQUICKOBJECT_H

#include <QObject>
#include <QQmlListProperty>

#define aqobject_cast(OBJECT) static_cast<AsemanQuickObject*>(OBJECT)

#define DEFINE_QML_PROEPRTY(TYPE, PNAME) \
    private: \
        QVariant _##PNAME; \
    Q_SIGNALS: \
        void PNAME##Changed(); \
    public: \
        Q_PROPERTY(TYPE PNAME READ PNAME WRITE set##PNAME NOTIFY PNAME##Changed) \
        TYPE PNAME() const { return _##PNAME.value<TYPE>(); } \
        void set##PNAME(TYPE PNAME) { SET_PROPERTY(PNAME) }

class AsemanQuickObjectPrivate;
class AsemanQuickObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQmlListProperty<QObject> items READ items NOTIFY itemsChanged)
    Q_CLASSINFO("DefaultProperty", "items")

public:
    Q_INVOKABLE explicit AsemanQuickObject(QObject *parent = Q_NULLPTR);
    virtual ~AsemanQuickObject();

    QQmlListProperty<QObject> items();
    QList<QObject*> itemsList() const;

    static bool isValid(AsemanQuickObject* obj);

Q_SIGNALS:
    void itemsChanged();

private:
    static void append(QQmlListProperty<QObject> *p, QObject *v);
    static int count(QQmlListProperty<QObject> *p);
    static QObject *at(QQmlListProperty<QObject> *p, int idx);
    static void clear(QQmlListProperty<QObject> *p);

private:
    AsemanQuickObjectPrivate *p;
};

#endif // ASEMANQUICKOBJECT_H
