#ifndef TONTOOLKITDEVICESITEM_H
#define TONTOOLKITDEVICESITEM_H

#include "tontoolkitdevices.h"

#include <QJSValue>

class TonToolkitDevicesItemPrivate;
class TonToolkitDevicesItem: public TonToolkitDevices
{
    Q_OBJECT
public:

    TonToolkitDevicesItem(QObject *parent = Q_NULLPTR);
    virtual ~TonToolkitDevicesItem();

public Q_SLOTS:
    bool getOpenPictures() Q_DECL_OVERRIDE;
    QVariantList getContactList(QJSValue asyncCallback);

Q_SIGNALS:
    void incomingImage( const QString & path );
    void selectImageResult( const QString & path );

private Q_SLOTS:
    void incoming_image( const QString & path );
    void select_image_result( const QString & path );

private:
    TonToolkitDevicesItemPrivate *p;
};

#endif // TONTOOLKITDEVICESITEM_H
