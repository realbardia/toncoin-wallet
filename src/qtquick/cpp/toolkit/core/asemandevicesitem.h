#ifndef ASEMANDEVICESITEM_H
#define ASEMANDEVICESITEM_H

#include "asemandevices.h"

#include <QJSValue>

class AsemanDevicesItemPrivate;
class AsemanDevicesItem: public AsemanDevices
{
    Q_OBJECT
public:

    AsemanDevicesItem(QObject *parent = Q_NULLPTR);
    virtual ~AsemanDevicesItem();

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
    AsemanDevicesItemPrivate *p;
};

#endif // ASEMANDEVICESITEM_H
