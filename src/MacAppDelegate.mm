#include "macappdelegate.h"

#include <QDebug>
#include <QSet>

#include "asemanapplicationitem.h"

#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject<NSApplicationDelegate>
@end

class MacAppDelegate::Private
{
public:
    AppDelegate *appDelegate;
    static QSet<MacAppDelegate*> objects;
};

@implementation AppDelegate

- (void)application:(NSApplication *)application openURLs:(NSArray<NSURL *> *)urls {
    for (NSURL *url in urls) {
        // Handle the deep link URL here
        QString str = QString::fromNSString(url.absoluteString);

        auto app = qobject_cast<AsemanApplicationItem*>(AsemanApplication::instance());
        if (app)
            Q_EMIT app->messageReceived(str);

        qDebug() << "Received deep link:" << str;
    }
}

@end

QSet<MacAppDelegate*> MacAppDelegate::Private::objects;

MacAppDelegate::MacAppDelegate()
{
    p = new Private;
    p->appDelegate = [[AppDelegate alloc] init];
    [[NSApplication sharedApplication] setDelegate:p->appDelegate];

    Private::objects.insert(this);
}

MacAppDelegate::~MacAppDelegate()
{
    Private::objects.remove(this);
    delete p;
}
