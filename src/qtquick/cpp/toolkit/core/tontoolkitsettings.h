#ifndef TONTOOLKITSETTINGS_H
#define TONTOOLKITSETTINGS_H

#include <QObject>
#include <QVariant>

class TonToolkitSettingsPrivate;
class TonToolkitSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString category READ category WRITE setCategory NOTIFY categoryChanged)
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
public:
    TonToolkitSettings(QObject *parent = Q_NULLPTR);
    virtual ~TonToolkitSettings();

    void setCategory(const QString &category);
    QString category() const;

    void setSource(const QString &source);
    QString source() const;

public Q_SLOTS:
    void setValue(const QString &key, const QVariant &value);
    QVariant value(const QString &key, const QVariant &defaultValue = QVariant());
    void remove(const QString &key);
    QStringList keys() const;
    void sync();

Q_SIGNALS:
    void categoryChanged();
    void sourceChanged();
    void valueChanged();

private Q_SLOTS:
    void propertyChanged();
    void initProperties();

private:
    TonToolkitSettingsPrivate *p;
};

#endif // TONTOOLKITSETTINGS_H
