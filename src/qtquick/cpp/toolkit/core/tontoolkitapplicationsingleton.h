#ifndef TONTOOLKITAPPLICATIONSINGLETON_H
#define TONTOOLKITAPPLICATIONSINGLETON_H

#include "tontoolkitapplicationitem.h"

class TonToolkitApplicationSingletonPrivate;
class TonToolkitApplicationSingleton : public TonToolkitApplicationItem
{
    Q_OBJECT
public:
    TonToolkitApplicationSingleton(QQmlEngine *engine);
    virtual ~TonToolkitApplicationSingleton();

private:
    TonToolkitApplicationSingletonPrivate *p;
};

#endif // TONTOOLKITAPPLICATIONSINGLETON_H
