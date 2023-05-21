#include "asemantranslationmanager.h"
#include "asemantools.h"

#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QDir>
#include <QDebug>
#include <QRegularExpression>
#include <QtQml>

class AsemanTranslationManager::Private
{
public:
    QTranslator *translator;
    QUrl sourceDirectory;
    QString localeName;
    QString fileName;
    QString delimiters;
};

AsemanTranslationManager::AsemanTranslationManager(QObject *parent) :
    QObject(parent)
{
    p = new Private;
    p->translator = 0;
}

void AsemanTranslationManager::setSourceDirectory(const QUrl &sourceDirectory)
{
    if(p->sourceDirectory == sourceDirectory)
        return;

    p->sourceDirectory = sourceDirectory;
    refresh();
    Q_EMIT sourceDirectoryChanged();
}

QUrl AsemanTranslationManager::sourceDirectory() const
{
    return p->sourceDirectory;
}

void AsemanTranslationManager::setLocaleName(const QString &localeName)
{
    if(p->localeName == localeName)
        return;

    p->localeName = localeName;
    refresh();
    Q_EMIT localeNameChanged();
}

QString AsemanTranslationManager::localeName() const
{
    return p->localeName;
}

void AsemanTranslationManager::setFileName(const QString &fileName)
{
    if(p->fileName == fileName)
        return;

    p->fileName = fileName;
    refresh();
    Q_EMIT fileNameChanged();
}

QString AsemanTranslationManager::fileName() const
{
    return p->fileName;
}

void AsemanTranslationManager::setDelimiters(const QString &delimiters)
{
    if(p->delimiters == delimiters)
        return;

    p->delimiters = delimiters;
    refresh();
    Q_EMIT delimitersChanged();
}

QString AsemanTranslationManager::delimiters() const
{
    return p->delimiters;
}

int AsemanTranslationManager::textDirection() const
{
    return QLocale(p->localeName).textDirection();
}

QMap<QString, QVariant> AsemanTranslationManager::translations() const
{
    QMap<QString, QVariant> res;
    QString path = AsemanTools::urlToLocalPath(p->sourceDirectory);

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

void AsemanTranslationManager::refresh()
{
    if(p->sourceDirectory.isEmpty() || p->fileName.isEmpty() || p->delimiters.isEmpty() || p->localeName.isEmpty())
        return;

    QString path = AsemanTools::urlToLocalPath(p->sourceDirectory);
    if(p->translator)
    {
        QCoreApplication::removeTranslator(p->translator);
        delete p->translator;
    }

    p->translator = new QTranslator(this);
    p->translator->load( QLocale(p->localeName), p->fileName, p->delimiters, path);

    QCoreApplication::installTranslator(p->translator);

    auto engine = qmlEngine(this);
    if (engine)
        engine->retranslate();

    Q_EMIT refreshed();
    Q_EMIT textDirectionChanged();
    Q_EMIT translationsChanged();
}

AsemanTranslationManager::~AsemanTranslationManager()
{
    if(p->translator)
        QCoreApplication::removeTranslator(p->translator);

    delete p;
}
