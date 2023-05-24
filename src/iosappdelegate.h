#ifndef IOSAPPDELEGATE_H
#define IOSAPPDELEGATE_H

#include <QObject>

class IOSAppDelegate
{
public:
    class Private;

    IOSAppDelegate();
    virtual ~IOSAppDelegate();

private:
    Private *p;
};

#endif // IOSAPPDELEGATE_H
