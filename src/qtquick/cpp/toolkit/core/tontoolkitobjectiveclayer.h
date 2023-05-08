#ifndef TONTOOLKITOBJECTIVECLAYER_H
#define TONTOOLKITOBJECTIVECLAYER_H

#include <QString>
#include <QVariantList>
#include <QObject>

#include <functional>

class TonToolkitObjectiveCLayer: public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal keyboardHeight READ keyboardHeight WRITE setKeyboardHeight NOTIFY keyboardHeightChanged)
public:
    TonToolkitObjectiveCLayer(QObject *parent = nullptr);
    virtual ~TonToolkitObjectiveCLayer();

    static qreal statusBarHeight();
    static qreal navigationBarHeight();
    static bool saveToCameraRoll(const QString &filePath);
    static void getContactList(std::function<void(const QVariantList &res)> asyncCallback = Q_NULLPTR);
    static void sharePaper(const QString &text);
    static QString deviceId();
    static bool openUrlInSafari(const QString &str);
    static void triggerVibrateFeedback();

    qreal keyboardHeight() const;
    void setKeyboardHeight(const qreal &keyboardHeight);

Q_SIGNALS:
    void keyboardHeightChanged();

private:
    qreal mKeyboardHeight = 0;
};

#endif // TONTOOLKITOBJECTIVECLAYER_H
