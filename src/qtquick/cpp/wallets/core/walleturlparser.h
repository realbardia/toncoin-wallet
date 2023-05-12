#ifndef WALLETURLPARSER_H
#define WALLETURLPARSER_H

#include <QObject>

class WalletUrlParser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString url READ url WRITE setUrl NOTIFY urlChanged)
    Q_PROPERTY(QString address READ address NOTIFY urlChanged)
    Q_PROPERTY(QString amount READ amount NOTIFY urlChanged)
    Q_PROPERTY(QString comment READ comment NOTIFY urlChanged)

public:
    WalletUrlParser(QObject *parent = nullptr);
    virtual ~WalletUrlParser();

    QString url() const;
    void setUrl(const QString &newUrl);

    QString address() const;
    QString amount() const;
    QString comment() const;

Q_SIGNALS:
    void urlChanged();

private:
    QString mUrl;
    QString mAddress;
    QString mAmount;
    QString mComment;
};

#endif // WALLETURLPARSER_H
