/**
  gameover.cpp
  Purpose: Dialog to alert that game is over
*/

#include "gameover.h"
#include "ui_gameover.h"

GameOver::GameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(accept()));
}

GameOver::~GameOver()
{
    delete ui;
}

//shows what score you achived
void GameOver::Show_score(const double &score)
{
    ui->score->setNum(score);
}

//sets name what player enters
QString GameOver::Enter_name()
{
    return ui->lineEdit->text();
}

