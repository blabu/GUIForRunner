#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QList>
#include "ui_widget.h"
#include "TcpLayerr.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(ConnectionInterface *sock, QWidget *parent = 0);
    ~Widget();
signals:
    void pressEnter(const QString &str);
    void changeData(const QString &str);
public slots:
    void setVariants(const QList<QString> &list);
private:
    ConnectionInterface* connection;
    Ui_widget *ui;
private slots:
    void changeDataInLineEdit(const QString &str);
    void enterIsPressed(const QString &str);
};

#endif // WIDGET_H
