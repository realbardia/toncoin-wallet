#include "tontoolkitapplicationsingleton.h"

class TonToolkitApplicationSingletonPrivate
{
public:
};

TonToolkitApplicationSingleton::TonToolkitApplicationSingleton(QQmlEngine *engine) :
    TonToolkitApplicationItem(engine)
{
    p = new TonToolkitApplicationSingletonPrivate;
}

TonToolkitApplicationSingleton::~TonToolkitApplicationSingleton()
{
    delete p;
}
