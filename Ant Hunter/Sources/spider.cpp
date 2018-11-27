/**
  spider.cpp
  Purpose: Makes a spider object
*/

#include "spider.h"
#include "math.h"

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

Spider::Spider(QGraphicsItem *target, QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    angle = 0;
    steps = 0;
    countForSteps = 0;
    setRotation(angle);

    this->target = target;

    timer = new QTimer();

    /** connects signal of timer to game slot of spider */
    connect(timer, &QTimer::timeout, this, &Spider::slotGameTimer);
    timer->start(15);
}

Spider::~Spider()
{

}

/**
 * sets the angle between 0 and 2*pi
 *
 * @brief normalizeAngle
 * @param angle
 * @return the angle between 0 and 2*pi
 */
static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
    {
        angle += TwoPi;
    }
    while (angle > TwoPi)
    {
        angle -= TwoPi;
    }
    return angle;
}

//limits a space where spider object can be
QRectF Spider::boundingRect() const
{
    return QRectF(-40,-50,80,100);
}

//paints a spider object
void Spider::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /** legs of spider */
    painter->setPen(QPen(Qt::black, 2));
    if(steps == 0)
    {
        // Left 1
        painter->drawLine(-24,-45,-28,-35);
        painter->drawLine(-28,-35,-22,-10);
        painter->drawLine(-22,-10,0,0);
        // Right 1
        painter->drawLine(24,-45,28,-35);
        painter->drawLine(28,-35,22,-10);
        painter->drawLine(22,-10,0,0);

        // Left 2
        painter->drawLine(-35,-38,-30,-18);
        painter->drawLine(-30,-18,-25,-3);
        painter->drawLine(-25,-3,0,0);
        // Right 2
        painter->drawLine(35,-38,30,-18);
        painter->drawLine(30,-18,25,-3);
        painter->drawLine(25,-3,0,0);

        // Left 3
        painter->drawLine(-35,38,-30,18);
        painter->drawLine(-30,18,-25,3);
        painter->drawLine(-25,3,0,0);
        // Right 3
        painter->drawLine(35,38,30,18);
        painter->drawLine(30,18,25,3);
        painter->drawLine(25,3,0,0);

        // Left 4
        painter->drawLine(-24,45,-28,35);
        painter->drawLine(-28,35,-22,10);
        painter->drawLine(-22,10,0,0);
        // Right 4
        painter->drawLine(24,45,28,35);
        painter->drawLine(28,35,22,10);
        painter->drawLine(22,10,0,0);
    }
    else if (steps == 1)
    {
        // Left 1
        painter->drawLine(-23,-40,-24,-30);
        painter->drawLine(-24,-30,-19,-9);
        painter->drawLine(-19,-9,0,0);
        // Right 1
        painter->drawLine(20,-50,23,-40);
        painter->drawLine(23,-40,15,-12);
        painter->drawLine(15,-12,0,0);

        // Left 2
        painter->drawLine(-30,-35,-27,-24);
        painter->drawLine(-27,-24,-23,-5);
        painter->drawLine(-23,-5,0,0);
        // Right 2
        painter->drawLine(40,-27,35,-10);
        painter->drawLine(35,-10,28,-1);
        painter->drawLine(28,-1,0,0);

        // Left 3
        painter->drawLine(-40,27,-35,10);
        painter->drawLine(-35,10,-28,1);
        painter->drawLine(-28,1,0,0);
        // Right 3
        painter->drawLine(30,35,27,24);
        painter->drawLine(27,24,23,5);
        painter->drawLine(23,5,0,0);

        // Left 4
        painter->drawLine(-20,50,-27,30);
        painter->drawLine(-27,30,-20,12);
        painter->drawLine(-20,12,0,0);
        // Right 4
        painter->drawLine(23,40,24,30);
        painter->drawLine(24,30,19,9);
        painter->drawLine(19,9,0,0);
    }
    else if (steps == 2)
    {
        // Left 1
        painter->drawLine(-20,-50,-23,-40);
        painter->drawLine(-23,-40,-15,-12);
        painter->drawLine(-15,-12,0,0);
        // Right 1
        painter->drawLine(23,-40,24,-30);
        painter->drawLine(24,-30,19,-9);
        painter->drawLine(19,-9,0,0);

        // Left 2
        painter->drawLine(-40,-27,-35,-10);
        painter->drawLine(-35,-10,-28,-1);
        painter->drawLine(-28,-1,0,0);
        // Right 2
        painter->drawLine(30,-35,27,-24);
        painter->drawLine(27,-24,23,-5);
        painter->drawLine(23,-5,0,0);

        // Left 3
        painter->drawLine(-30,35,-27,24);
        painter->drawLine(-27,24,-23,5);
        painter->drawLine(-23,5,0,0);
        // Right 3
        painter->drawLine(40,27,35,10);
        painter->drawLine(35,10,28,1);
        painter->drawLine(28,1,0,0);

        // Left 4
        painter->drawLine(-23,40,-24,30);
        painter->drawLine(-24,30,-19,9);
        painter->drawLine(-19,9,0,0);
        // Right 4
        painter->drawLine(20,50,27,30);
        painter->drawLine(27,30,20,12);
        painter->drawLine(20,12,0,0);
    }
    painter->setPen(QPen(Qt::black, 1));

    /** left jaw */
    QPainterPath path1(QPointF(0, -20));
    path1.cubicTo(0, -20, -5, -25, -3, -35);
    path1.cubicTo(-3,-35,-15,-25,-8,-17);
    path1.cubicTo(-8,-17,-5,15,0,-20 );
    painter->setBrush(Qt::gray);
    painter->drawPath(path1);

    /** right jaw */
    QPainterPath path2(QPointF(0, -20));
    path2.cubicTo(0, -20, 5, -25, 3, -35);
    path2.cubicTo(3,-35,15,-25,8,-17);
    path2.cubicTo(8,-17,5,15,0,-20 );
    painter->setBrush(Qt::gray);
    painter->drawPath(path2);

    /** head of spider */
    painter->setBrush(QColor(33,29,29));
    painter->drawEllipse(-10,-25,20,15);

    /** body of spider */
    painter->drawEllipse(-15, -15, 30, 30);

    /** back part of spider */
    painter->drawEllipse(-20, 0, 40,50);
    painter->setPen(QPen(QColor(247,11,11),3));
    painter->drawLine(-10,25,10,25);
    painter->drawLine(0,35,0,15);

    /** left eye */
    painter->setPen(QPen(Qt::black,1));
    painter->setBrush(Qt::cyan);
    painter->drawEllipse(-8,-23,6,8);

    /** right eye */
    painter->setBrush(Qt::cyan);
    painter->drawEllipse(2,-23,6,8);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

//slot for gaming timer of spider
void Spider::slotGameTimer()
{
    QLineF lineToTarget(QPointF(0, 0), mapFromItem(target, 0, 0));
    qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
    if (lineToTarget.dy() < 0)
        angleToTarget = TwoPi - angleToTarget;
    angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);

    /** Rotation of spider which depends on where is ant: left- or rightside */
    if(angleToTarget > 0 && angleToTarget < Pi)
    {
        // Rotate left
        if(angleToTarget > Pi / 5)
        {
            angle = -15;
        }
        else if(angleToTarget > Pi / 10)
        {
           angle = -5;
        }
        else
        {
           angle = -1;
        }
    }
    else if(angleToTarget <= TwoPi && angleToTarget > (TwoPi - Pi))
    {
        // Rotate right
        if(angleToTarget < (TwoPi - Pi / 5))
        {
            angle = 15;
        }
        else if(angleToTarget < (TwoPi - Pi / 10))
        {
            angle = 5;
        }
        else
        {
            angle = 1;
        }
    }
    else if(angleToTarget == 0)
    {
        angle = 0;
    }

    setRotation(rotation() + angle);

    /** running to the spider */
    if(lineToTarget.length() >= 40)
    {
        setPos(mapToParent(0, -(qrand() % ((4 + 1) - 1) + 1)));

        countForSteps++;
        if(countForSteps == 6)
        {
            steps = 1;
            update(QRectF(-40,-50,80,100));
        }
        else if (countForSteps == 12)
        {
            steps = 0;
            update(QRectF(-40,-50,80,100));
        }
        else if (countForSteps == 18)
        {
            steps = 2;
            update(QRectF(-40,-50,80,100));
        }
        else if (countForSteps == 24)
        {
            steps = 0;
            update(QRectF(-40,-50,80,100));
            countForSteps = 0;
        }
    }

    /** Checks if spider come across with some object */
    QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()
                                                           << mapToScene(0, 0)
                                                           << mapToScene(-2, -2)
                                                           << mapToScene(2, -2));
    /** Checks if this object was ant */
         foreach (QGraphicsItem *item, foundItems) {
        if (item == this)
            continue;
        if(item == target){
            emit signalCheckGameOver();
        }
    }

    /** checks if spider does not cross the border of game space */
    if(this->x() - 10 < -250)
    {
        this->setX(-240);
    }
    if(this->x() + 10 > 250)
    {
        this->setX(240);
    }
    if(this->y() - 10 < -250)
    {
        this->setY(-240);
    }
    if(this->y() + 10 > 250)
    {
        this->setY(240);
    }
}


//pauses a game
void Spider::pause()
{
    if(timer->isActive())
    {
        timer->stop();
    }
    else
    {
        timer->start(15);
    }
}
