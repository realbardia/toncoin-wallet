#ifndef ASEMANTOOLSITEM_H
#define ASEMANTOOLSITEM_H

#include <QJSValue>
#include <QObject>

#include "asemantools.h"

class AsemanToolsItemPrivate;
class AsemanToolsItem : public AsemanTools
{
    Q_OBJECT
public:
    AsemanToolsItem(QObject *parent = Q_NULLPTR);
    virtual ~AsemanToolsItem();

public Q_SLOTS:
    static QString variantToJson(QVariant value, bool compact = false);
    static QVariant jsonToVariant(const QString &json);

    void jsDelayCall(int ms, const QJSValue &value);
    void imageResize(const QString &path, const QSize &size, const QString &dest, const QJSValue &callback);

    QObject *createObject(const QUrl &qml);

    static void setInAppStoreProperty(QObject *store, const QString &propertyName, const QString &value);

protected:
    void timerEvent(QTimerEvent *e) Q_DECL_OVERRIDE;

private:
    AsemanToolsItemPrivate *p;
};

#endif // ASEMANTOOLSITEM_H
