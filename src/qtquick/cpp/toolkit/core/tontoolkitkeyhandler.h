#ifndef TONTOOLKITKEYHANDLER_H
#define TONTOOLKITKEYHANDLER_H

#include <QObject>
#include <QWindow>

class TonToolkitKeyHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject* window READ window WRITE setWindow NOTIFY windowChanged)
    Q_PROPERTY(qint32 modifiers READ modifiers NOTIFY modifiersChanged)
    Q_PROPERTY(qint32 scanCode READ scanCode WRITE setScanCode NOTIFY scanCodeChanged)
    Q_PROPERTY(qint32 key READ key WRITE setKey NOTIFY keyChanged)
    Q_PROPERTY(QPointF mousePosition READ mousePosition NOTIFY mousePositionChanged)
    Q_PROPERTY(qint32 mouseKey READ mouseKey NOTIFY mouseKeyChanged)

    class Private;

public:
    TonToolkitKeyHandler(QObject *parent = Q_NULLPTR);
    virtual ~TonToolkitKeyHandler();

    void setWindow(QObject *window);
    QObject *window() const;

    qint32 key() const;
    qint32 modifiers() const;
    qint32 mouseKey() const;
    QPointF mousePosition() const;

    qint32 scanCode() const;
    void setScanCode(qint32 scanCode);

Q_SIGNALS:
    void windowChanged();
    void keyChanged();
    void modifiersChanged();
    void scanCodeChanged();
    void mousePositionChanged();
    void mouseKeyChanged();

    void pressed(qint32 modifiers, qint32 key, qint32 scanCode);
    void released(qint32 modifiers, qint32 key, qint32 scanCode);

public Q_SLOTS:

protected:
    bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;
    void setKey(qint32 key);
    void setModifiers(qint32 modifiers);
    void setMouseKey(qint32 mouseKey);
    void setMousePosition(const QPointF &mousePosition);

private:
    Private *p;
};

typedef TonToolkitKeyHandler QAsemanKeyHandler;

#endif // TONTOOLKITKEYHANDLER_H
