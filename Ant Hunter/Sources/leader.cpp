/**
  leader.cpp
  Purpose: widget to add player's name and result in ResultBoard
*/

#include "leader.h"
#include "ui_leader.h"

Leader::Leader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Leader)
{
    ui->setupUi(this);
}

Leader::~Leader()
{
    delete ui;
}

//sets name of a player
void Leader::Set_Name(const QString &name)
{
    ui->label->setText(name);
}

//sets score what player achived
void Leader::Set_Value(const double &value)
{
    ui->label_2->setNum(value);
}
