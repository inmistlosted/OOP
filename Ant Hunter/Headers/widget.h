/**
  widget.h
  Purpose: main gaming space

  @author inmistlosted
  @version 1.0
*/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QShortcut>
#include <QTimer>
#include <QDebug>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include <ant.h>
#include <pear.h>
#include <spider.h>

#define GAME_STOPED 0
#define GAME_STARTED 1

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:


private slots:
    /**
     * Deletes pears if ant come across with it
     *
     * @brief slotDeletePear
     * @param item
     */
    void slotDeletePear(QGraphicsItem * item);

    /**
     * Creates pears
     *
     * @brief slotCreatePear
     */
    void slotCreatePear();

    /**
     * Starts game
     *
     * @brief on_pushButton_clicked
     */
    void on_pushButton_clicked();

    /**
     * Ends game
     *
     * @brief slotGameOver
     */
    void slotGameOver();

    /**
     * Pauses game
     *
     * @brief slotPause
     */
    void slotPause();

private:
    Ui::Widget *ui;

    /** Graphics Scene */
    QGraphicsScene *scene;

    /** Ant object */
    Ant *ant;

    /** timer */
    QTimer *timer;

    /** timer for creating pears */
    QTimer *timerCreatePear;

    /** List with pears */
    QList<QGraphicsItem *> pears;

    /** game score */
    double count;

    /** Spider object */
    Spider *spider;

    /** hot key to pause game */
    QShortcut *pauseKey;

    /** current state of a game */
    int gameState;
};

#endif // WIDGET_H
