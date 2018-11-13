#ifndef ALARM_H
#define ALARM_H

#include <QWidget>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QMessageBox>

namespace Ui {
class Alarm;
}

class Alarm : public QWidget
{
    Q_OBJECT

public:
    explicit Alarm(QWidget *parent = nullptr);
    ~Alarm();

    void setTime(const QString& time); //функція для встановлення отриманого часу
    QString getTime(); //функція для отримання часу

public slots:
    void Alrm(); //функція де описано як працює будильник
    void Remove(); //функція яка видаляє будильник

private:
    Ui::Alarm *ui;
    QTimer *timer;
};

#endif // ALARM_H
