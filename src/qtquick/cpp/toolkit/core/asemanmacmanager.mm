#include "asemanmacmanager.h"
#include <Cocoa/Cocoa.h>
#include <QSemaphore>

#import <LocalAuthentication/LocalAuthentication.h>

void AsemanMacManager::removeTitlebarFromWindow(double r, double g, double b)
{
    QWindowList windows = QGuiApplication::allWindows();
    QWindow* win = windows.first();
    long winId = win->winId();

    auto nativeView = reinterpret_cast<NSView *>(winId);
    auto nativeWindow = [nativeView window];

    nativeWindow.titlebarAppearsTransparent=YES;
    nativeWindow.titleVisibility = NSWindowTitleHidden;

    auto color = [NSColor colorWithRed:r green:g blue:b alpha:1.0f];
    nativeWindow.backgroundColor = color;

    [nativeWindow setStyleMask:[nativeWindow styleMask] | NSWindowTitleHidden];
    [nativeWindow setTitlebarAppearsTransparent:YES];
}

bool AsemanMacManager::hasBiometric()
{
    LAContext *context = [[LAContext alloc] init];
    NSError *error = nil;

    if ([context canEvaluatePolicy:LAPolicyDeviceOwnerAuthenticationWithBiometrics error:&error]) {
        return true;
    } else {
        return false;
    }
}

bool AsemanMacManager::biometricCheck()
{
    LAContext *context = [[LAContext alloc] init];
    NSError *error = nil;

    if (![context canEvaluatePolicy:LAPolicyDeviceOwnerAuthenticationWithBiometrics error:&error])
        return false;

    auto res = new bool;
    auto semaphore = new QSemaphore;
    [context evaluatePolicy:LAPolicyDeviceOwnerAuthenticationWithBiometrics
              localizedReason:@"Authenticate with Touch ID"
                        reply:^(BOOL success, NSError *error) {
        if (success) {
            *res = true;
        } else {
            *res = false;
        }
        semaphore->release(1);
    }];

    semaphore->acquire(1);
    auto r = *res;
    delete semaphore;
    delete res;
    return r;
}
