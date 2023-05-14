#ifndef MACMANAGER_H
#define MACMANAGER_H

#include <QGuiApplication>
#include <QWindow>

class TonToolkitMacManager
{
public:
    static void removeTitlebarFromWindow(double r, double g, double b);

    static bool hasBiometric();
    static bool biometricCheck();
};
#endif // MACMANAGER_H
