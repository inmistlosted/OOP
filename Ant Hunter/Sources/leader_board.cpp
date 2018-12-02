/**
  leader_board.cpp
  Purpose: makes ResultBoard
*/

#include "leader_board.h"
#include "ui_leader_board.h"

Leader_board::Leader_board(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Leader_board)
{
    ui->setupUi(this);
}

Leader_board::~Leader_board()
{
    delete ui;
}

//adds player's name and result
void Leader_board::Add_Leader(QWidget *leader)
{
    ui->leadersLayout->addWidget(leader);
}
