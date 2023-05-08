#define PROPERTY_KEY(PROPERTY) QString(p->caregory.isEmpty()? QString(PROPERTY) : p->caregory + QStringLiteral("/") + QString(PROPERTY))

#include "tontoolkitsettings.h"

#include <QMetaObject>
#include <QMetaProperty>
#include <QDir>
#include <QSettings>
#include <QFileInfo>
#include <QTimer>
#include <QDebug>

class TonToolkitSettingsPrivate
{
public:
    QHash<QByteArray, QByteArray> signalsProperties;
    QSettings *settings;
    QString caregory;
    QString source;
};

TonToolkitSettings::TonToolkitSettings(QObject *parent) : QObject(parent)
{
    p = new TonToolkitSettingsPrivate;

#ifdef Q_OS_WASM
    p->settings = new QSettings;

    std::function<void(void)> *testSettingsReady = new std::function<void(void)>();
    *testSettingsReady = [=](){
        if (p->settings->status() == QSettings::NoError) {
            delete testSettingsReady;
            initProperties();
        } else {
            QTimer::singleShot(10, this, *testSettingsReady);
        }
    };
    (*testSettingsReady)();
#else
    p->settings = 0;

    initProperties();
#endif
}

void TonToolkitSettings::setCategory(const QString &category)
{
    if(p->caregory == category)
        return;

    p->caregory = category;
    initProperties();
    Q_EMIT categoryChanged();
}

QString TonToolkitSettings::category() const
{
    return p->caregory;
}

void TonToolkitSettings::setSource(const QString &source)
{
    if(p->source == source)
        return;

    p->source = source;
#ifndef Q_OS_WASM
    if(p->settings)
        delete p->settings;

    p->settings = 0;
    if(!p->source.isEmpty())
    {
        QDir().mkpath(QFileInfo(p->source).dir().path());
        p->settings = new QSettings(p->source, QSettings::IniFormat, this);
        initProperties();
    }
#endif

    Q_EMIT sourceChanged();
}

QString TonToolkitSettings::source() const
{
    return p->source;
}

void TonToolkitSettings::setValue(const QString &key, const QVariant &value)
{
    if(!p->settings)
        return;

    p->settings->setValue(PROPERTY_KEY(key), value);
    Q_EMIT valueChanged();
}

QVariant TonToolkitSettings::value(const QString &key, const QVariant &defaultValue)
{
    if(!p->settings)
        return QVariant();

    return p->settings->value(PROPERTY_KEY(key), defaultValue);
}

void TonToolkitSettings::remove(const QString &key)
{
    if(!p->settings)
        return;
    p->settings->remove(PROPERTY_KEY(key));
}

QStringList TonToolkitSettings::keys() const
{
    QStringList result;
    if(!p->settings)
        return result;

    p->settings->beginGroup(p->caregory);
    result = p->settings->childKeys();
    p->settings->endGroup();
    return result;
}

void TonToolkitSettings::sync()
{
    if(!p->settings)
        return;

    p->settings->sync();
    initProperties();
}

void TonToolkitSettings::propertyChanged()
{
    if(sender() != this)
        return;

    const int signalIndex = senderSignalIndex();
    if(signalIndex == -1)
        return;

    QMetaMethod signalObj = metaObject()->method(signalIndex);
    const QByteArray &propertyName = p->signalsProperties.value(signalObj.methodSignature());
    const QVariant &value = property(propertyName);
    if(p->settings)
        p->settings->setValue( PROPERTY_KEY(QString::fromUtf8(propertyName)), value);

    Q_EMIT valueChanged();
}

void TonToolkitSettings::initProperties()
{
    if(!p->settings || p->caregory.isEmpty())
        return;

    for (const auto &signalSign: p->signalsProperties.keys())
        disconnect(this, QByteArray(QByteArray::number(QSIGNAL_CODE)+signalSign),
                   this, SLOT(propertyChanged()));

    p->signalsProperties.clear();

    const QMetaObject *meta = metaObject();
    for(int i=0; i<meta->propertyCount(); i++)
    {
        QMetaProperty property = meta->property(i);
        const QByteArray &propertyName = property.name();
        const QByteArray &signalSign = property.notifySignal().methodSignature();
        if(propertyName == "source" || propertyName == "category" || propertyName == "objectName")
            continue;

        p->signalsProperties[signalSign] = propertyName;
        if(p->settings)
        {
            QVariant value = p->settings->value(PROPERTY_KEY( QString::fromUtf8(propertyName) ));
            if(value != QObject::property(propertyName) && value.isValid())
                setProperty(propertyName, value);
        }

        connect(this, QByteArray(QByteArray::number(QSIGNAL_CODE)+signalSign),
                this, SLOT(propertyChanged()));
    }
}

TonToolkitSettings::~TonToolkitSettings()
{
    delete p;
}
