#include "asemantoolsitem.h"

#include <QJsonDocument>
#include <QTimerEvent>
#include <QtQml>

class AsemanToolsItemPrivate
{
public:
    QHash<int, QJSValue> js_delay_call_timers;
};

AsemanToolsItem::AsemanToolsItem(QObject *parent) :
    AsemanTools(parent)
{
    p = new AsemanToolsItemPrivate;
}

QVariant AsemanToolsItem::jsonToVariant(const QString &json)
{
    return QJsonDocument::fromJson(json.toUtf8()).toVariant();
}

QString AsemanToolsItem::variantToJson(QVariant value, bool compact)
{
    value = value.value<QJSValue>().toVariant();
    return QString::fromUtf8(QJsonDocument::fromVariant(value).toJson(compact? QJsonDocument::Compact : QJsonDocument::Indented));
}

void AsemanToolsItem::jsDelayCall(int ms, const QJSValue &value)
{
    p->js_delay_call_timers[ startTimer(ms) ] = value;
}

void AsemanToolsItem::imageResize(const QString &path, const QSize &size, const QString &dest, const QJSValue &callback)
{
    AsemanTools::imageResize(path, size, dest, this, [callback](bool stt){
        QJSValue(callback).call(QJSValueList() << stt);
    });
}

QObject *AsemanToolsItem::createObject(const QUrl &qml)
{
    auto engine = qmlEngine(this);
    if (!engine)
        return nullptr;

    auto com = new QQmlComponent(engine, qml, this);
    auto obj = com->create();
    obj->setParent(this);

    return obj;
}

void AsemanToolsItem::setInAppStoreProperty(QObject *store, const QString &propertyName, const QString &value)
{
#ifdef QT_PURCHASING_LIB
    if(!store)
        return;
    QList<QObject*> childs = store->children();
    childs.prepend(store);
    for(QObject *obj: childs)
        if( qobject_cast<QInAppStore*>(obj) )
            qobject_cast<QInAppStore*>(obj)->setPlatformProperty(propertyName, value);
#else
    Q_UNUSED(store)
    Q_UNUSED(propertyName)
    Q_UNUSED(value)
#endif
}

void AsemanToolsItem::timerEvent(QTimerEvent *e)
{
    if(p->js_delay_call_timers.contains(e->timerId()))
    {
        p->js_delay_call_timers.take(e->timerId()).call();
    }
    else
        QObject::timerEvent(e);
}

AsemanToolsItem::~AsemanToolsItem()
{
    delete p;
}
