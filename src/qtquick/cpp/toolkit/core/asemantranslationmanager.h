#ifndef ASEMANTRANSLATIONMANAGER_H
#define ASEMANTRANSLATIONMANAGER_H

#include <QUrl>
#include <QObject>
#include <QMap>
#include <QVariant>

class AsemanTranslationManager : public QObject
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
    AsemanTranslationManager(QObject *parent = Q_NULLPTR);
    virtual ~AsemanTranslationManager();

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

#endif // ASEMANTRANSLATIONMANAGER_H
