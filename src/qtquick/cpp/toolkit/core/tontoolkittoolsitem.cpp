#include "tontoolkittoolsitem.h"

#include <QJsonDocument>
#include <QTimerEvent>

class TonToolkitToolsItemPrivate
{
public:
    QHash<int, QJSValue> js_delay_call_timers;
};

TonToolkitToolsItem::TonToolkitToolsItem(QObject *parent) :
    TonToolkitTools(parent)
{
    p = new TonToolkitToolsItemPrivate;
}

QVariant TonToolkitToolsItem::jsonToVariant(const QString &json)
{
    return QJsonDocument::fromJson(json.toUtf8()).toVariant();
}

QString TonToolkitToolsItem::variantToJson(QVariant value, bool compact)
{
    value = value.value<QJSValue>().toVariant();
    return QString::fromUtf8(QJsonDocument::fromVariant(value).toJson(compact? QJsonDocument::Compact : QJsonDocument::Indented));
}

void TonToolkitToolsItem::jsDelayCall(int ms, const QJSValue &value)
{
    p->js_delay_call_timers[ startTimer(ms) ] = value;
}

void TonToolkitToolsItem::imageResize(const QString &path, const QSize &size, const QString &dest, const QJSValue &callback)
{
    TonToolkitTools::imageResize(path, size, dest, this, [callback](bool stt){
        QJSValue(callback).call(QJSValueList() << stt);
    });
}

void TonToolkitToolsItem::setInAppStoreProperty(QObject *store, const QString &propertyName, const QString &value)
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

void TonToolkitToolsItem::timerEvent(QTimerEvent *e)
{
    if(p->js_delay_call_timers.contains(e->timerId()))
    {
        p->js_delay_call_timers.take(e->timerId()).call();
    }
    else
        QObject::timerEvent(e);
}

TonToolkitToolsItem::~TonToolkitToolsItem()
{
    delete p;
}
