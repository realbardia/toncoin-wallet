#include "iosappdelegate.h"

#include <QDebug>
#include <QSet>

#include "asemanapplicationitem.h"

#import <UIKit/UIKit.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>
@end

class IOSAppDelegate::Private
{
public:
    AppDelegate *appDelegate;
    static QSet<IOSAppDelegate*> objects;
};

@implementation AppDelegate

- (void)handleDeepLink:(NSURL *)deepLinkURL {
    // Handle the deep link URL here

    auto app = qobject_cast<AsemanApplicationItem*>(AsemanApplication::instance());
    if (app) {
        NSString *urlString = [deepLinkURL absoluteString];
        auto str = QString::fromNSString(urlString);
        QMetaObject::invokeMethod(app, "messageReceived", Qt::QueuedConnection, Q_ARG(QString, str));
    }
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Check if the app was launched from a deep link
    NSURL *deepLinkURL = [launchOptions objectForKey:UIApplicationLaunchOptionsURLKey];
    if (deepLinkURL) {
        [self handleDeepLink:deepLinkURL];
    }

    // Other code...

    return YES;
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
    // Handle the deep link
    [self handleDeepLink:url];

    // Return YES if the deep link was successfully handled, or NO otherwise
    return YES;
}

@end

QSet<IOSAppDelegate*> IOSAppDelegate::Private::objects;

IOSAppDelegate::IOSAppDelegate()
{
    p = new Private;
    p->appDelegate = [[AppDelegate alloc] init];
    [[UIApplication sharedApplication] setDelegate:p->appDelegate];

    Private::objects.insert(this);
}

IOSAppDelegate::~IOSAppDelegate()
{
    Private::objects.remove(this);
    delete p;
}
