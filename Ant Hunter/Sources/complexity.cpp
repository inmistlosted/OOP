/**
  complexity.cpp
  Purpose: Dialog for choosing a complexity of the game
*/

#include "complexity.h"
#include "ui_complexity.h"

Complexity::Complexity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Complexity)
{
    ui->setupUi(this);
    connect(ui->Btn, SIGNAL(clicked()), SLOT(accept()));
}

Complexity::~Complexity()
{
    delete ui;
}

//gives a level of complexity
int Complexity::getComplexity()
{
    if(ui->radioButton->isChecked())
    {
        return 3;
    }
    else if(ui->radioButton_2->isChecked())
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
