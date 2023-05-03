#ifndef TONTOOLKIT_MACROS_H
#define TONTOOLKIT_MACROS_H

#include <QtGlobal>

#if defined(Q_OS_WASM)
#define WEBASM_DEVICE
#else
#if defined(Q_OS_ANDROID) || defined(Q_OS_IOS) || defined(Q_OS_WINPHONE) || defined(Q_OS_UBUNTUTOUCH)
#define TOUCH_DEVICE
#else
#define DESKTOP_DEVICE
#if defined(Q_OS_LINUX) || defined(Q_OS_OPENBSD)
#define DESKTOP_LINUX
#endif
#endif
#endif

#endif // TONTOOLKIT_MACROS_H
