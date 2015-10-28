#include "widget.h"
#include "ui_widget.h"
#include <QtSerialPort/QtSerialPort>
#include <QMessageBox>
#include <QNetworkReply>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    port = new QSerialPort(this);
    port->setPortName("/dev/ttyACM1");
    port->setBaudRate(115200);
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setStopBits(QSerialPort::OneStop);
    port->setFlowControl(QSerialPort::HardwareControl);
    if (port->open(QIODevice::ReadWrite)) {
        qDebug() << "Ok";
    }else
        qDebug() << port->errorString();
    QTimer *timer = new QTimer(this);
    connect (timer, SIGNAL(timeout()), this, SLOT(check()));
    timer->start(0);
    gw = new GraphWidget(this);
    ui->verticalLayout->addWidget(gw);
    resp=0;

}

void Widget::check()
{
    if (port->canReadLine())
    {
        QByteArray ba = (port->readLine());
        QList<QByteArray> lines = ba.split('\n');
        foreach (QByteArray line, lines)
        {
            if (line.startsWith("T"))
            {
                qDebug() << "Temp" << line;
                QByteArray num = line.mid(1,line.length()-1);
                qDebug() << "Temp" << num;
                float num1= num.toFloat();
                gw->temps.append(num1);
                gw->update();
            }if (line.startsWith("B"))
            {

                qDebug() << "BPM" << line;
                QByteArray num = line.mid(1,line.length()-1);
                ui->label->setText(QString("BPM ").append(num));
//                ui->heart->show();


            }if (line.startsWith("S"))
            {
                qDebug() << "Heart" << line;
                QByteArray num = line.mid(1,line.length()-1).trimmed();
                float num1= num.toInt();
                qDebug() << "Heart" << num << num1;
                gw->heart.append(num1);
            }

            if (line.startsWith("Resp"))
            {
                resp++;
                qDebug() << "Resp" << line;
            }
            ui->label_2->setText(QString("Resp: ").append(QString::number(resp)));
//            else
//                qDebug() << "BPM" << line;
        }
    }
}

Widget::~Widget()
{
    delete ui;
}

