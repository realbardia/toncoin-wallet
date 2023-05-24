#ifndef MACAPPDELEGATE_H
#define MACAPPDELEGATE_H

#include <QObject>

class MacAppDelegate
{
public:
    class Private;

    MacAppDelegate();
    virtual ~MacAppDelegate();

private:
    Private *p;
};

#endif // MACAPPDELEGATE_H
