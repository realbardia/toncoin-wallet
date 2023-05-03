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

#include "tontoolkittranslationmanager.h"
#include "tontoolkittools.h"

#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QDir>
#include <QDebug>
#include <QRegularExpression>

class TonToolkitTranslationManager::Private
{
public:
    QTranslator *translator;
    QUrl sourceDirectory;
    QString localeName;
    QString fileName;
    QString delimiters;
};

TonToolkitTranslationManager::TonToolkitTranslationManager(QObject *parent) :
    QObject(parent)
{
    p = new Private;
    p->translator = 0;
}

void TonToolkitTranslationManager::setSourceDirectory(const QUrl &sourceDirectory)
{
    if(p->sourceDirectory == sourceDirectory)
        return;

    p->sourceDirectory = sourceDirectory;
    refresh();
    Q_EMIT sourceDirectoryChanged();
}

QUrl TonToolkitTranslationManager::sourceDirectory() const
{
    return p->sourceDirectory;
}

void TonToolkitTranslationManager::setLocaleName(const QString &localeName)
{
    if(p->localeName == localeName)
        return;

    p->localeName = localeName;
    refresh();
    Q_EMIT localeNameChanged();
}

QString TonToolkitTranslationManager::localeName() const
{
    return p->localeName;
}

void TonToolkitTranslationManager::setFileName(const QString &fileName)
{
    if(p->fileName == fileName)
        return;

    p->fileName = fileName;
    refresh();
    Q_EMIT fileNameChanged();
}

QString TonToolkitTranslationManager::fileName() const
{
    return p->fileName;
}

void TonToolkitTranslationManager::setDelimiters(const QString &delimiters)
{
    if(p->delimiters == delimiters)
        return;

    p->delimiters = delimiters;
    refresh();
    Q_EMIT delimitersChanged();
}

QString TonToolkitTranslationManager::delimiters() const
{
    return p->delimiters;
}

int TonToolkitTranslationManager::textDirection() const
{
    return QLocale(p->localeName).textDirection();
}

QMap<QString, QVariant> TonToolkitTranslationManager::translations() const
{
    QMap<QString, QVariant> res;
    QString path = TonToolkitTools::urlToLocalPath(p->sourceDirectory);

    QRegularExpression rx(p->fileName + p->delimiters + QStringLiteral("(\\w+)\\.qm"));
    QStringList files = QDir(path).entryList(QStringList()<<QStringLiteral("*.qm"), QDir::Files);
    for(const QString &file: files)
    {
        auto i = rx.match(file);
        if (!i.hasMatch())
            continue;

        QString cap = i.captured(1);
        res[cap] = QLocale(cap).nativeLanguageName();
    }

    return res;
}

void TonToolkitTranslationManager::refresh()
{
    if(p->sourceDirectory.isEmpty() || p->fileName.isEmpty() || p->delimiters.isEmpty() || p->localeName.isEmpty())
        return;

    QString path = TonToolkitTools::urlToLocalPath(p->sourceDirectory);
    if(p->translator)
    {
        QCoreApplication::removeTranslator(p->translator);
        delete p->translator;
    }

    p->translator = new QTranslator(this);
    p->translator->load( QLocale(p->localeName), p->fileName, p->delimiters, path);

    QCoreApplication::installTranslator(p->translator);

    Q_EMIT refreshed();
    Q_EMIT textDirectionChanged();
    Q_EMIT translationsChanged();
}

TonToolkitTranslationManager::~TonToolkitTranslationManager()
{
    if(p->translator)
        QCoreApplication::removeTranslator(p->translator);

    delete p;
}
