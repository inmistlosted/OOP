#include "alarm.h"
#include "ui_alarm.h"

Alarm::Alarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Alarm)
{
    ui->setupUi(this);
    //створення таймера
    timer = new QTimer(this);
    timer->setInterval(1000);

    //підключення сигналів до слотів
    connect(timer, SIGNAL(timeout()), this, SLOT(Alrm()));
    connect(ui->remove_btn, SIGNAL(clicked()), this, SLOT(Remove()));

    //запуск таймера
    timer->start();
}

Alarm::~Alarm()
{
    delete ui;
}

//функція для встановлення отриманого часу
void Alarm::setTime(const QString& time)
{
    ui->time_label->setText(time);
}

//функція для отримання часу
QString Alarm::getTime()
{
    return ui->time_label->text();
}

//функція де описано як працює будильник
void Alarm::Alrm()
{
    if(ui->time_label->text() == QTime::currentTime().toString())
    {
        //виводить попередження що спрацював будильник
        QMessageBox msg;
        QApplication::beep();
        msg.warning(this, tr("ALARM"), ui->time_label->text(), QMessageBox::Ok);
        msg.setStyleSheet("color: white");
        this->close();
    }
}

//функція яка видаляє будильник
void Alarm::Remove()
{
    timer->stop();
    this->close();
}
