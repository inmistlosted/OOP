#include "alarm.h"
#include "ui_alarm.h"

Alarm::Alarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Alarm)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(1000);

    connect(timer, SIGNAL(timeout()), this, SLOT(Alrm()));
    connect(ui->remove_btn, SIGNAL(clicked()), this, SLOT(Remove()));

    timer->start();
}

Alarm::~Alarm()
{
    delete ui;
}

void Alarm::setTime(const QString& time)
{
    ui->time_label->setText(time);
}

QString Alarm::getTime()
{
    return ui->time_label->text();
}

void Alarm::Alrm()
{
    if(ui->time_label->text() == QTime::currentTime().toString())
    {
        QMessageBox msg;
        QApplication::beep();
        msg.warning(this, tr("ALARM"), ui->time_label->text(), QMessageBox::Ok);
        msg.setStyleSheet("color: white");
        this->close();
    }
}

void Alarm::Remove()
{
    timer->stop();
    this->close();
}
