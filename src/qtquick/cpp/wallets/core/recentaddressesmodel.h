#ifndef RECENTADDRESSESMODEL_H
#define RECENTADDRESSESMODEL_H

#include "abstractwalletmodel.h"

class RecentAddressesModel : public AbstractWalletModel
{
    Q_OBJECT
public:
    RecentAddressesModel(QObject *parent = nullptr);
    virtual ~RecentAddressesModel();

Q_SIGNALS:

private:
};

#endif // RECENTADDRESSESMODEL_H
