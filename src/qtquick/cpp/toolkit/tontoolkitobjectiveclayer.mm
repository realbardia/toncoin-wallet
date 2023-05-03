#include "tontoolkitobjectiveclayer.h"
#include "tontoolkittools.h"

#import <UIKit/UIKit.h>
#import <SafariServices/SafariServices.h>
#import <Foundation/Foundation.h>

#include <QSet>
#include <QUrl>
#include <QDesktopServices>
#include <QDebug>
#include <QTimer>
#include <QEventLoop>

QSet<TonToolkitObjectiveCLayer*> ObjectiveCLayer_mObjects;

@interface TonToolkitObjectiveCLayer_core : NSObject;
@end

@implementation TonToolkitObjectiveCLayer_core

#pragma mark - Methods

- (void)keyboardWillShow:(NSNotification *)notification
{
    CGFloat height = [[[notification userInfo] objectForKey:UIKeyboardFrameEndUserInfoKey] CGRectValue].size.height;
    for (auto o: ObjectiveCLayer_mObjects)
        o->setKeyboardHeight(height);
}

@end


TonToolkitObjectiveCLayer::TonToolkitObjectiveCLayer(QObject *parent)
    : QObject(parent)
{

    ObjectiveCLayer_mObjects.insert(this);
    TonToolkitObjectiveCLayer_core *core = [TonToolkitObjectiveCLayer_core alloc];

    [[NSNotificationCenter defaultCenter] addObserver:core selector:@selector(keyboardWillShow:) name:UIKeyboardWillShowNotification object:nil];
}

TonToolkitObjectiveCLayer::~TonToolkitObjectiveCLayer()
{
    ObjectiveCLayer_mObjects.remove(this);
}

qreal TonToolkitObjectiveCLayer::statusBarHeight()
{
    CGFloat menuBarHeight = [UIApplication sharedApplication].statusBarFrame.size.height;
    return menuBarHeight;
}

qreal TonToolkitObjectiveCLayer::navigationBarHeight()
{
    CGFloat navBarHeight = 0;
    if (statusBarHeight() > 24)
        return 22;
    return navBarHeight;
}

bool TonToolkitObjectiveCLayer::saveToCameraRoll(const QString &filePath)
{
    auto path = TonToolkitTools::urlToLocalPath(filePath);

    NSString *imagePath = path.toNSString();
    UIImage *image = [[UIImage alloc] initWithContentsOfFile:imagePath];

    UIImageWriteToSavedPhotosAlbum(image, nil, nil, nil);
    return true;
}

void TonToolkitObjectiveCLayer::getContactList(std::function<void(const QVariantList &res)> asyncCallback)
{
    asyncCallback(QVariantList());
}

void TonToolkitObjectiveCLayer::sharePaper(const QString &text)
{
    UIViewController *controller = [UIApplication sharedApplication].keyWindow.rootViewController;
    NSString *textToShare = text.toNSString();
    UIActivityViewController *activityVC = [[UIActivityViewController alloc] initWithActivityItems:@[textToShare] applicationActivities:nil];
    activityVC.excludedActivityTypes = @[UIActivityTypePrint, UIActivityTypeCopyToPasteboard, UIActivityTypeAssignToContact, UIActivityTypeSaveToCameraRoll]; //Exclude whichever aren't relevant
            [controller presentViewController:activityVC animated:YES completion:nil];
}

QString TonToolkitObjectiveCLayer::deviceId()
{
    UIDevice *device = [UIDevice currentDevice];
    NSString  *currentDeviceId = [[device identifierForVendor]UUIDString];
    return QString::fromNSString(currentDeviceId);
}

bool TonToolkitObjectiveCLayer::openUrlInSafari(const QString &str)
{
    return false;
}

void TonToolkitObjectiveCLayer::triggerVibrateFeedback()
{
    // Create an instance of the feedback generator
    auto generator = [[UIImpactFeedbackGenerator alloc] initWithStyle:UIImpactFeedbackStyleLight];

    // Trigger the feedback
    [generator impactOccurred];
}

qreal TonToolkitObjectiveCLayer::keyboardHeight() const
{
    return mKeyboardHeight;
}

void TonToolkitObjectiveCLayer::setKeyboardHeight(const qreal &keyboardHeight)
{
    if (mKeyboardHeight == keyboardHeight)
        return;
    mKeyboardHeight = keyboardHeight;
    Q_EMIT keyboardHeightChanged();
}
