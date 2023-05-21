#ifndef ASEMANAPPLICATIONSINGLETON_H
#define ASEMANAPPLICATIONSINGLETON_H

#include "asemanapplicationitem.h"

class AsemanApplicationSingletonPrivate;
class AsemanApplicationSingleton : public AsemanApplicationItem
{
    Q_OBJECT
public:
    AsemanApplicationSingleton(QQmlEngine *engine);
    virtual ~AsemanApplicationSingleton();

private:
    AsemanApplicationSingletonPrivate *p;
};

#endif // ASEMANAPPLICATIONSINGLETON_H
