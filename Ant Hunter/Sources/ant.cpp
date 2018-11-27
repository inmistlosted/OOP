/**
  ant.cpp
  Purpose: Makes an ant object
*/

#include "ant.h"

Ant::Ant(QObject *parent) :
     QObject(parent), QGraphicsItem()
{
   angle = 0;
   steps = 1;
   countForSteps = 0;
   setRotation(angle);

  // m_player = new QMediaPlayer(this);
  // m_playlist = new QMediaPlaylist(m_player);

  // move = new QSound("://Music/ant_move.wav");
 //move->setLoops(QSound::Infinite);

 //  m_player->setPlaylist(m_playlist);
  // m_playlist->addMedia(QUrl("qrc://Music/ant_move.wav"));
 //  m_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
}

Ant::~Ant()
{

}

//limits a space where ant object can be
QRectF Ant::boundingRect() const
{
    return QRectF(-40,-50,80,100);
}

//paints an ant object
void Ant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        /** paints legs of ant */
        painter->setPen(QPen(Qt::black, 2));
        if(steps == 0)
        {
            // Left 1
            painter->drawLine(-24,-37,-22,-25);
            painter->drawLine(-22,-25,-17,-15);
            painter->drawLine(-17,-15,-10,-5);
            // Right 1
            painter->drawLine(37,-28,28,-18);
            painter->drawLine(28,-18,24,-8);
            painter->drawLine(24,-8,10,-5);

            // Left 2
            painter->drawLine(-35,-20,-25,-11);
            painter->drawLine(-25,-11,-14,-5);
            painter->drawLine(-14,-5,0,5);
            // Right 2
            painter->drawLine(37,-12,32,-4);
            painter->drawLine(32,-4,24,2);
            painter->drawLine(24,2,0,5);

            // Left 3
            painter->drawLine(-35,35,-26,24);
            painter->drawLine(-26,24,-16,16);
            painter->drawLine(-16,16,0,0);
            // Right 3
            painter->drawLine(37,26,32,17);
            painter->drawLine(32,17,24,8);
            painter->drawLine(24,8,0,0);
        }
        else if (steps == 1)
        {
            // Left 1
            painter->drawLine(-32,-32,-25,-22);
            painter->drawLine(-25,-22,-20,-12);
            painter->drawLine(-20,-12,-10,-5);
            // Right 1
            painter->drawLine(32,-32,25,-22);
            painter->drawLine(25,-22,20,-12);
            painter->drawLine(20,-12,10,-5);

            // Left 2
            painter->drawLine(-39,-15,-30,-8);
            painter->drawLine(-30,-8,-18,-2);
            painter->drawLine(-18,-2,0,5);
            // Right 2
            painter->drawLine(39,-15,30,-8);
            painter->drawLine(30,-8,18,-2);
            painter->drawLine(18,-2,0,5);

            // Left 3
            painter->drawLine(-39,30,-30,20);
            painter->drawLine(-30,20,-20,12);
            painter->drawLine(-20,12,0,0);
            // Right 3
            painter->drawLine(39,30,30,20);
            painter->drawLine(30,20,20,12);
            painter->drawLine(20,12,0,0);
        }
        else if (steps == 2)
        {
            // Left 1
            painter->drawLine(-37,-28,-28,-18);
            painter->drawLine(-28,-18,-24,-8);
            painter->drawLine(-24,-8,-10,-5);
            // Right 1
            painter->drawLine(24,-37,22,-25);
            painter->drawLine(22,-25,17,-15);
            painter->drawLine(17,-15,10,-5);

            // Left 2
            painter->drawLine(-37,-12,-32,-4);
            painter->drawLine(-32,-4,-24,2);
            painter->drawLine(-24,2,0,5);
            // Right 2
            painter->drawLine(35,-20,25,-11);
            painter->drawLine(25,-11,14,-5);
            painter->drawLine(14,-5,0,5);

            // Left 3
            painter->drawLine(-37,26,-32,17);
            painter->drawLine(-32,17,-24,8);
            painter->drawLine(-24,8,0,0);
            // Right 3
            painter->drawLine(35,35,26,24);
            painter->drawLine(26,24,16,16);
            painter->drawLine(16,16,0,0);
        }

        /** antennae */
        QPainterPath path(QPointF(-5,-34));
        path.cubicTo(-5,-34, 0,-36,0,-30);
        path.cubicTo(0,-30, 0,-36,5,-34);
        painter->drawLine(-10, -50, 6, 4);
        painter->drawLine(10, -50, -4, -6);
        painter->setBrush(Qt::NoBrush);
        painter->drawPath(path);
        painter->setPen(QPen(Qt::black, 1));

        /** first body circle of ant */
        painter->setBrush(Qt::darkRed);
        painter->drawEllipse(-15, -25, 30, 30);

        /** second body circle of ant */
        painter->setBrush(Qt::darkRed);
        painter->drawEllipse(-15, 0, 30, 50);

        /** head of ant */
        painter->drawEllipse(-15, -35, 30, 20);

        /** eyes */
        painter->setBrush(Qt::black);
        painter->drawEllipse(-12, -30, 8, 10);
        painter->drawEllipse(3, -30, 8, 10);

        Q_UNUSED(option);
        Q_UNUSED(widget);
}

//slot for gaming timer of ant
void Ant::slotGameTimer()
{
/** checks if one of control keys was pressed before counting steps */
        if(GetAsyncKeyState(VK_LEFT) ||
           GetAsyncKeyState(VK_RIGHT) ||
           GetAsyncKeyState(VK_UP) ||
           GetAsyncKeyState(VK_DOWN))
        {
            /** checks which key was pressed by turn and rotate object*/
            if(GetAsyncKeyState(VK_LEFT))
            {
                angle -= 5;
                setRotation(angle);
            }
            if(GetAsyncKeyState(VK_RIGHT))
            {
                angle += 5;
                setRotation(angle);
            }

            /** moves object on 5px forward */
            if(GetAsyncKeyState(VK_UP))
            {
                setPos(mapToParent(0, -2));
            }

            /** moves object on 5px backward */
            if(GetAsyncKeyState(VK_DOWN))
            {
                setPos(mapToParent(0, 2));
            }

            /** makes legs of ant move */
            countForSteps++;
            if(countForSteps == 4)
            {
                steps = 2;
                update(QRectF(-40,-50,80,100));
            }
            else if (countForSteps == 8)
            {
                steps = 1;
                update(QRectF(-40,-50,80,100));
            }
            else if (countForSteps == 12)
            {
                steps = 0;
                update(QRectF(-40,-50,80,100));
            }
            else if (countForSteps == 16)
            {
                steps = 1;
                update(QRectF(-40,-50,80,100));
                countForSteps = 0;
            }
         //   m_player->play();
         //   move->play();
        }
        else
        {
          //  m_player->stop();
          //  move->stop();
        }

        /** checks if ant does not cross the border of game space */
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


        /** checks if ant come across with other object */
        QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()
                                                               << mapToScene(0, 0)
                                                               << mapToScene(-20, -20)
                                                               << mapToScene(20, -20));

        foreach (QGraphicsItem *item, foundItems) {
            if (item == this)
                continue;
            emit signalCheckItem(item);
        }
}


