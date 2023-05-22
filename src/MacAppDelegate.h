#ifndef MACAPPDELEGATE_H
#define MACAPPDELEGATE_H

#include <QObject>

class MacAppDelegate
{
public:
    class Private;

    MacAppDelegate();
    virtual ~MacAppDelegate();

Q_SIGNALS:
    void urlRequested(const QString &url);

private:
    Private *p;
};

#endif // MACAPPDELEGATE_H
