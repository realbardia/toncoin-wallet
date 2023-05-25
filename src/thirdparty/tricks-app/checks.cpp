#include "checks.h"
#include "asemanapplication.h"

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QDir>
#include <QApplication>
#include <QSettings>
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include <QRegularExpression>
#include <QPalette>

#ifndef Q_OS_IOS
#include <QProcess>
#endif

#define DONT_ASK_BEFORE_CREATE_SHORTCUT

void Checks::checkLinuxDesktopIcon()
{
#if defined(Q_OS_LINUX) && !defined(Q_OS_ANDROID)
    auto exePath = qApp->applicationFilePath();
    if (qEnvironmentVariableIsSet("APPIMAGE"))
        exePath = qEnvironmentVariable("APPIMAGE");

    QSettings settings(AsemanApplication::homePath() + "/checks.ini", QSettings::IniFormat);
    if (settings.value("PreventLinuxDesktopWarn").toString() == exePath)
        return;

    const auto desktops = QDir(qApp->applicationDirPath()).entryList({"*.desktop"}, QDir::Files);
    if (desktops.count() != 1)
        return;

    const auto pngs = QDir(qApp->applicationDirPath()).entryList({"*.png"}, QDir::Files);
    if (pngs.count() != 1)
        return;

    auto createShortcut = [&](){
        auto app_install_path = QDir::homePath() + "/.local/share/applications/";
        auto icon_install_path = QDir::homePath() + "/.local/share/icons/";

        QDir().mkpath(app_install_path);
        QDir().mkpath(icon_install_path);

        QFile::remove(app_install_path + '/' + desktops.first());
        QFile::remove(icon_install_path + '/' + pngs.first());

        QFile f_in(qApp->applicationDirPath() + '/' + desktops.first());
        QFile f_out(app_install_path + '/' + desktops.first());
        if (QFile::copy(qApp->applicationDirPath() + '/' + pngs.first(), icon_install_path + '/' + pngs.first())
            && f_in.open(QFile::ReadOnly) && f_out.open(QFile::WriteOnly))
        {
            QMap<QString, QString> entries;
            entries["StartupNotify"] = "true";
            entries["Type"] = "Application";
            entries["Version"] = "1.0";
            entries["Exec"] = exePath + " --no-check-desktop-installation %U";
            entries["Icon"] = QString(pngs.first()).remove(".png");

            auto data = QString::fromUtf8(f_in.readAll());
            for (const auto &[k, v]: entries.toStdMap())
            {
                QRegularExpression rx("\\n" + k + "=.+\\n");
                data.replace(rx, "\n");
                data += k + "=" + v + "\n";
            }

            f_out.write(data.toUtf8());

            f_in.close();
            f_out.close();
        }
        else
        {
            QMessageBox::critical(Q_NULLPTR, QDialog::tr("Shortcut"), QDialog::tr("Failed to install application shortcut"));
            return;
        }

        QProcess::startDetached("update-icon-caches", {icon_install_path});
        QProcess::startDetached("xdg-desktop-menu", {"forceupdate", "--mode", "user"});

        settings.setValue("PreventLinuxDesktopWarn", exePath);
    };

#if defined(DONT_ASK_BEFORE_CREATE_SHORTCUT)
    createShortcut();
#else
    auto check = new QCheckBox(QDialog::tr("Do not ask again"));
    auto label = new QLabel(QDialog::tr("Do you want to install application shortcut to the main menu?"));

    auto labelLayout = new QVBoxLayout;
    labelLayout->addWidget(label);
    labelLayout->addWidget(check);
    labelLayout->setSpacing(0);

    auto icon = new QLabel();
    icon->setPixmap(QPixmap(":/ton/common/icons/dialog-information.png").scaledToWidth(64, Qt::SmoothTransformation));

    auto centerLayout = new QHBoxLayout;
    centerLayout->addWidget(icon);
    centerLayout->addLayout(labelLayout);

    auto buttons = new QDialogButtonBox(QDialogButtonBox::Yes | QDialogButtonBox::No);

    auto layout = new QVBoxLayout;
    layout->addLayout(centerLayout);
    layout->addWidget(buttons);

    QDialog dialog;
    dialog.setLayout(layout);
    dialog.setWindowTitle(QDialog::tr("Shortcut"));
    dialog.connect(buttons, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    dialog.connect(buttons, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    dialog.connect(&dialog, &QDialog::accepted, createShortcut);
    dialog.connect(&dialog, &QDialog::rejected, [&](){
        if (check->isChecked())
            settings.setValue("PreventLinuxDesktopWarn", exePath);
    });

    dialog.exec();
#endif
#endif
}

void Checks::checkWindowsDeeplink()
{
    const auto appPath = qApp->applicationFilePath().replace("/", "\\");
    for (const auto &uri: QStringList({"ton", "tonium"}))
    {
        QSettings settings("HKEY_CURRENT_USER\\Software\\Classes\\" + uri, QSettings::NativeFormat);
        settings.setValue("URL Protocol", "");
        settings.setValue("DefaultIcon/.", appPath);
        settings.setValue("shell/open/command/.", appPath + " \"%1\"");
    }
}
