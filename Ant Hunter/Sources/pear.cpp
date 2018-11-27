/**
  pear.cpp
  Purpose: Makes a pear object
*/


#include "pear.h"

Pear::Pear(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    color = qrand() % ((4 + 1) - 1) + 1;
}

Pear::~Pear()
{

}

//limits a space where pear can be
QRectF Pear::boundingRect() const
{
    return QRectF(-20,-30,40,50);
}

//paints a pear object
void Pear::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /** body of pear */
    QPainterPath path(QPointF(0,-20));
    path.cubicTo(0,-20, -10,-15,  -12,-8);
    path.cubicTo(-12,-8, -20,12, -10,15);
    path.cubicTo(-10,15, -5,20, 0,16);
    path.cubicTo(0,16, 5,20, 10,15);
    path.cubicTo(10,15, 20,12, 12,-8);
    path.cubicTo(12,-8, 10,-15,  0,-20);

    /* Randomly chooses color of a pear */
    switch (color)
    {
    case 1:
        painter->setBrush(Qt::red);
        break;
    case 2:
        painter->setBrush(Qt::green);
        break;
    case 3:
        painter->setBrush(Qt::darkYellow);
        break;
    case 4:
        painter->setBrush(Qt::yellow);
        break;
    }
    painter->drawPath(path);

    /** tail of a pear */
    painter->setPen(QPen(Qt::black, 2));
    QPainterPath path2(QPointF(0,-20));
    path2.cubicTo(0,-20,4,-28,10,-30);
    painter->setBrush(Qt::NoBrush);
    painter->drawPath(path2);

    /** first leaf of a pear */
    painter->setPen(QPen(Qt::black, 1));
    QPainterPath path3(QPointF(0,-20));
    path3.cubicTo(0,-20,-2,-30,-15,-30);
    path3.cubicTo(-15,-30,-14,-12,0,-20);
    painter->setBrush(Qt::darkGreen);
    painter->drawPath(path3);

    /** second leaf of a pear */
    painter->setPen(QPen(Qt::black, 1));
    QPainterPath path4(QPointF(0,-20));
    path4.cubicTo(0,-20,2,-10,15,-10);
    path4.cubicTo(15,-10,14,-28,0,-20);
    painter->setBrush(Qt::darkGreen);
    painter->drawPath(path4);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
