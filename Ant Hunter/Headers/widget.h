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
#include <complexity.h>
#include <gameover.h>
#include <leader.h>
#include <leader_board.h>

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
    void DeletePear(QGraphicsItem * item);

    /**
     * Creates pears
     *
     * @brief slotCreatePear
     */
    void CreatePear();

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
    void GameIsOver();

    /**
     * Pauses game
     *
     * @brief slotPause
     */
    void Pause();

    /**
     * opens dialog to choose complexity
     *
     * @brief Choose_Complexity
     */
    void Choose_Complexity();

    /**
     * opens ResultBoard
     *
     * @brief Open_LeaderBoard
     */
    void Open_ResultBoard();

    /**
     * adds player's result to ResultBoard
     *
     * @brief Add_Leader
     */
    void Add_Leader();

private:
    Ui::Widget *ui;

    /** dialog to choose complexity */
    Complexity *com;

    /** dialog to alert that game is over */
    GameOver *game_over;

    /** widget for player's name and result */
    Leader *contestant;

    /** creates ResultBoard */
    Leader_board *board;

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
