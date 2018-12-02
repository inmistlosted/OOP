/**
  gameover.h
  Purpose: Dialog to alert that game is over
*/

#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>
#include <QString>

namespace Ui {
class GameOver;
}

class GameOver : public QDialog
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = nullptr);
    ~GameOver();

public slots:
    /**
     * shows what score you achived
     *
     * @brief Show_score
     * @param score
     */
    void Show_score(const double& score);

    /**
     * sets name what player enters
     *
     * @brief Enter_name
     * @return entered name
     */
    QString Enter_name();

private:
    Ui::GameOver *ui;
};

#endif // GAMEOVER_H
