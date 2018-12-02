#include "leaders.h"
#include "ui_leaders.h"

Leaders::Leaders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Leaders)
{
    ui->setupUi(this);
}

Leaders::~Leaders()
{
    delete ui;
}
