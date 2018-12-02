/**
  leader_board.h
  Purpose: makes ResultBoard
*/

#ifndef LEADER_BOARD_H
#define LEADER_BOARD_H

#include <QDialog>

namespace Ui {
class Leader_board;
}

class Leader_board : public QDialog
{
    Q_OBJECT

public:
    explicit Leader_board(QWidget *parent = nullptr);
    ~Leader_board();

    /**
     * adds player's name and result
     *
     * @brief Add_Leader
     * @param leader
     */
    void Add_Leader(QWidget *leader);

private:
    Ui::Leader_board *ui;
};

#endif // LEADER_BOARD_H
