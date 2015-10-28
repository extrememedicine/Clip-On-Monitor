#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort/QtSerialPort>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include "graphwidget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
//     QList<QByteArray> = UnprecessedCommands;
private slots:
    void check();

private:
    GraphWidget *gw;
    Ui::Widget *ui;
    QSerialPort *port;
    int resp;
};

#endif // WIDGET_H
