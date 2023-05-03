#ifndef TONTOOLKITTOOLSITEM_H
#define TONTOOLKITTOOLSITEM_H

#include <QJSValue>
#include <QObject>

#include "tontoolkittools.h"

class TonToolkitToolsItemPrivate;
class TonToolkitToolsItem : public TonToolkitTools
{
    Q_OBJECT
public:
    TonToolkitToolsItem(QObject *parent = Q_NULLPTR);
    virtual ~TonToolkitToolsItem();

public Q_SLOTS:
    static QString variantToJson(QVariant value, bool compact = false);
    static QVariant jsonToVariant(const QString &json);

    void jsDelayCall(int ms, const QJSValue &value);
    void imageResize(const QString &path, const QSize &size, const QString &dest, const QJSValue &callback);

    static void setInAppStoreProperty(QObject *store, const QString &propertyName, const QString &value);

protected:
    void timerEvent(QTimerEvent *e) Q_DECL_OVERRIDE;

private:
    TonToolkitToolsItemPrivate *p;
};

#endif // TONTOOLKITTOOLSITEM_H
