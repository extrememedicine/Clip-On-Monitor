#include "graphwidget.h"

#include <QPainter>
#include <QDebug>

GraphWidget::GraphWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumHeight(200);
}

void GraphWidget::paintEvent(QPaintEvent *)
{
    int i = 0;
    int lastpoint = 0;
    QPainter painter(this);
    painter.drawLine(0,0,10,10);
//    qDebug() << "temps.count()" << temps.count();
    painter.drawPoint(12,12);

    painter.setPen(Qt::black);
    foreach (float temp, temps)
    {
        painter.drawPoint(i,((temp-20.0)*100.0)-200);
//        qDebug() << i << (temp-20.0)*5.0;
        i++;
    } i = 0;
    painter.setPen(Qt::red);
    foreach (float heartreading, heart)
    {
        painter.drawLine(i,lastpoint,i,heartreading/4);
        lastpoint=heartreading/4;
        qDebug() << i << heartreading;
        i++;
    }
    if (i > 200)
    {
    temps.clear();
    heart.clear();
    }
}

