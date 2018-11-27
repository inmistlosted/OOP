/**
  ant.h
  Purpose: Makes an ant object
*/

#ifndef ANT_H
#define ANT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSound>

#include <windows.h>

class Ant : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit Ant(QObject *parent = nullptr);
    ~Ant();

 //   QMediaPlayer * m_player;
 //   QMediaPlaylist * m_playlist;
 //   QSound *move;

signals:
    /**
     * checks what object came across with ant
     *
     * @brief signalCheckItem
     * @param item
     */
    void signalCheckItem(QGraphicsItem *item);

public slots:
    /**
     * slot for gaming timer of ant
     *
     * @brief slotGameTimer
     */
    void slotGameTimer();

protected:
    /**
     * limits a space where ant object can be
     *
     * @brief boundingRect
     * @return
     */
    QRectF boundingRect() const;

    /**
     * paints an ant object
     *
     * @brief paint
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    /** angle of rotation of ant object */
    qreal angle;
    /** number of position of legs of ant */
    int steps;
    /** counter for positions of legs */
    int countForSteps;
    //QMediaPlayer * m_player;
    //QMediaPlaylist * m_playlist;
    //QSound *move;
};

#endif // TRIANGLE_H
