#include "timer_diag.h"
#include "ui_timer_diag.h"

Timer_diag::Timer_diag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timer_diag)
{
    ui->setupUi(this);
    //підключення сигналів до слотів
    connect(ui->Add_btn, SIGNAL(clicked()), SLOT(accept()));
}

Timer_diag::~Timer_diag()
{
    delete ui;
}

//отримує введені години
int Timer_diag::getHours()
{
    int h = ui->spinBox_h->value();
    return h;
}

//отримує введені хвилини
int Timer_diag::getMin()
{
    int m = ui->spinBox_m->value();
    return m;
}

//отримує введені секунди
int Timer_diag::getSec()
{
    int s = ui->spinBox_s->value();
    return s;
}


