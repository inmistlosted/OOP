/**
  spider.h
  Purpose: Makes a spider object
*/

#ifndef SPIDER_H
#define SPIDER_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <QDebug>


class Spider : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit Spider(QGraphicsItem * target, QObject *parent = nullptr);
    ~Spider();

    /**
     * pauses a game
     *
     * @brief pause
     */
    void pause();

signals:
    /**
     * Signal to call Game Over
     *
     * @brief signalCheckGameOver
     */
    void signalCheckGameOver();

public slots:

protected:
    /**
     * limits a space where spider object can be
     *
     * @brief boundingRect
     * @return coordinates of space, where spider object can be
     */
    QRectF boundingRect() const;

    /**
     * paints a spider object
     *
     * @brief paint
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    /** angle of rotation of spider object */
    qreal angle;

    /** number of position of legs of spider */
    int steps;

    /** counter for positions of legs */
    int countForSteps;

    /** timer of spider which makes it move */
    QTimer *timer;

    /** target of spider(ant) */
    QGraphicsItem *target;

private slots:
    /**
     * slot for gaming timer of spider
     *
     * @brief slotGameTimer
     */
    void slotGameTimer();   // Слот игрового таймера паука
};

#endif // SPIDER_H
