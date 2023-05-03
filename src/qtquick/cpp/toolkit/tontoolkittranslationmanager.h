/*
    Copyright (C) 2017 TonToolkit Team
    http://tontoolkit.co

    TonToolkitQtTools is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    TonToolkitQtTools is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TONTOOLKITTRANSLATIONMANAGER_H
#define TONTOOLKITTRANSLATIONMANAGER_H

#include <QUrl>
#include <QObject>
#include <QMap>
#include <QVariant>

#include "tontoolkitgui_global.h"

class LIBQTTONTOOLKIT_GUI_EXPORT TonToolkitTranslationManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl sourceDirectory READ sourceDirectory WRITE setSourceDirectory NOTIFY sourceDirectoryChanged)
    Q_PROPERTY(QString localeName READ localeName WRITE setLocaleName NOTIFY localeNameChanged)
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)
    Q_PROPERTY(QString delimiters READ delimiters WRITE setDelimiters NOTIFY delimitersChanged)
    Q_PROPERTY(QString refresher READ refresher NOTIFY refreshed)
    Q_PROPERTY(int textDirection READ textDirection NOTIFY textDirectionChanged)
    Q_PROPERTY(QVariantMap translations READ translations NOTIFY translationsChanged)

    class Private;

public:
    TonToolkitTranslationManager(QObject *parent = Q_NULLPTR);
    virtual ~TonToolkitTranslationManager();

    void setSourceDirectory(const QUrl &source);
    QUrl sourceDirectory() const;

    void setLocaleName(const QString &localeName);
    QString localeName() const;

    void setFileName(const QString &fileName);
    QString fileName() const;

    void setDelimiters(const QString &delimiters);
    QString delimiters() const;

    QString refresher() const { return QString(); }

    int textDirection() const;

    QMap<QString, QVariant> translations() const;

Q_SIGNALS:
    void sourceDirectoryChanged();
    void localeNameChanged();
    void fileNameChanged();
    void delimitersChanged();
    void refreshed();
    void textDirectionChanged();
    void translationsChanged();

public Q_SLOTS:

private:
    void refresh();

private:
    Private *p;
};

#endif // TONTOOLKITTRANSLATIONMANAGER_H
