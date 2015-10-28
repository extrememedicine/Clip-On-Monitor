#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QList>
#include <QPaintEvent>
#include <QWidget>

class GraphWidget  : public QWidget
{
public:
    GraphWidget(QWidget *parent);
    QList <float> temps;
    QList <int> heart;

protected:
    void paintEvent(QPaintEvent *);
};

#endif // GRAPHWIDGET_H
