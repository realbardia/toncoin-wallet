#include "asemanobjectiveclayer.h"
#include "asemantools.h"

#import <UIKit/UIKit.h>
#import <SafariServices/SafariServices.h>
#import <Foundation/Foundation.h>
#import <LocalAuthentication/LocalAuthentication.h>

#include <QSet>
#include <QUrl>
#include <QDesktopServices>
#include <QDebug>
#include <QTimer>
#include <QEventLoop>

QSet<AsemanObjectiveCLayer*> ObjectiveCLayer_mObjects;

@interface AsemanObjectiveCLayer_core : NSObject;
@end

@implementation AsemanObjectiveCLayer_core

#pragma mark - Methods

- (void)keyboardWillShow:(NSNotification *)notification
{
    CGFloat height = [[[notification userInfo] objectForKey:UIKeyboardFrameEndUserInfoKey] CGRectValue].size.height;
    for (auto o: ObjectiveCLayer_mObjects)
        o->setKeyboardHeight(height);
}

@end


AsemanObjectiveCLayer::AsemanObjectiveCLayer(QObject *parent)
    : QObject(parent)
{

    ObjectiveCLayer_mObjects.insert(this);
    static AsemanObjectiveCLayer_core *core = [AsemanObjectiveCLayer_core alloc];

    [[NSNotificationCenter defaultCenter] addObserver:core selector:@selector(keyboardWillShow:) name:UIKeyboardWillShowNotification object:nil];
}

AsemanObjectiveCLayer::~AsemanObjectiveCLayer()
{
    ObjectiveCLayer_mObjects.remove(this);
}

qreal AsemanObjectiveCLayer::statusBarHeight()
{
    CGFloat menuBarHeight = [UIApplication sharedApplication].statusBarFrame.size.height;
    return menuBarHeight;
}

qreal AsemanObjectiveCLayer::navigationBarHeight()
{
    CGFloat navBarHeight = 0;
    if (statusBarHeight() > 24)
        return 22;
    return navBarHeight;
}

bool AsemanObjectiveCLayer::saveToCameraRoll(const QString &filePath)
{
    auto path = AsemanTools::urlToLocalPath(filePath);

    NSString *imagePath = path.toNSString();
    UIImage *image = [[UIImage alloc] initWithContentsOfFile:imagePath];

    UIImageWriteToSavedPhotosAlbum(image, nil, nil, nil);
    return true;
}

void AsemanObjectiveCLayer::getContactList(std::function<void(const QVariantList &res)> asyncCallback)
{
    asyncCallback(QVariantList());
}

void AsemanObjectiveCLayer::sharePaper(const QString &text)
{
    UIViewController *controller = [UIApplication sharedApplication].keyWindow.rootViewController;
    NSString *textToShare = text.toNSString();
    UIActivityViewController *activityVC = [[UIActivityViewController alloc] initWithActivityItems:@[textToShare] applicationActivities:nil];
    activityVC.excludedActivityTypes = @[UIActivityTypePrint, UIActivityTypeCopyToPasteboard, UIActivityTypeAssignToContact, UIActivityTypeSaveToCameraRoll]; //Exclude whichever aren't relevant
            [controller presentViewController:activityVC animated:YES completion:nil];
}

QString AsemanObjectiveCLayer::deviceId()
{
    UIDevice *device = [UIDevice currentDevice];
    NSString  *currentDeviceId = [[device identifierForVendor]UUIDString];
    return QString::fromNSString(currentDeviceId);
}

bool AsemanObjectiveCLayer::openUrlInSafari(const QString &str)
{
    return false;
}

void AsemanObjectiveCLayer::triggerVibrateFeedback()
{
    // Create an instance of the feedback generator
    auto generator = [[UIImpactFeedbackGenerator alloc] initWithStyle:UIImpactFeedbackStyleMedium];

    // Trigger the feedback
    [generator impactOccurred];
}

qreal AsemanObjectiveCLayer::keyboardHeight() const
{
    return mKeyboardHeight;
}

void AsemanObjectiveCLayer::setKeyboardHeight(const qreal &keyboardHeight)
{
    if (mKeyboardHeight == keyboardHeight)
        return;
    mKeyboardHeight = keyboardHeight;
    Q_EMIT keyboardHeightChanged();
}

bool AsemanObjectiveCLayer::hasBiometric()
{
    LAContext *context = [[LAContext alloc] init];
    NSError *error = nil;

    if ([context canEvaluatePolicy:LAPolicyDeviceOwnerAuthenticationWithBiometrics error:&error]) {
        return true;
    } else {
        return false;
    }
}

bool AsemanObjectiveCLayer::biometricCheck()
{
    LAContext *context = [[LAContext alloc] init];
    NSError *error = nil;

    if (![context canEvaluatePolicy:LAPolicyDeviceOwnerAuthenticationWithBiometrics error:&error])
        return false;

    auto res = new bool;
    auto loop = new QEventLoop;
    [context evaluatePolicy:LAPolicyDeviceOwnerAuthenticationWithBiometrics
              localizedReason:@"Authenticating"
                        reply:^(BOOL success, NSError *error) {
        if (success) {
            *res = true;
        } else {
            *res = false;
        }
        loop->exit();
    }];

    loop->exec();
    auto r = *res;
    delete loop;
    delete res;
    return r;
}
