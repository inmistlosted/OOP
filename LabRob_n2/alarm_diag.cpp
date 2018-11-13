#include "alarm_diag.h"
#include "ui_alarm_diag.h"

Alarm_diag::Alarm_diag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alarm_diag)
{
    ui->setupUi(this);
    //підключення сигналів до слотів
    connect(ui->Add_btn, SIGNAL(clicked()), SLOT(accept()));
}

Alarm_diag::~Alarm_diag()
{
    delete ui;
}

//отримує введені години
int Alarm_diag::getHours()
{
    int h = ui->spinBox_h->value();
    return h;
}

//отримує введені хвилини
int Alarm_diag::getMin()
{
    int m = ui->spinBox_m->value();
    return m;
}

//отримує введені секунди
int Alarm_diag::getSec()
{
    int s = ui->spinBox_s->value();
    return s;
}

//повертає введений час
QTime Alarm_diag::alrm()
{
    QTime t(getHours(), getMin(), getSec());
    return t;
}
