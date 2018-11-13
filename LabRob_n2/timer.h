#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QTimer>
#include <QMessageBox>
#include <QLCDNumber>

namespace Ui {
class Timer;
}

class Timer : public QWidget
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent = nullptr);
    ~Timer();

    void setHours(const int& hours); //встановлює години
    void setMin(const int& mins); //встановлює хвилини
    void setSec(const int& secs); //встановлює секунди

public slots:
    void Tmr(); //функція де описано як працює таймер
    void Remove(); //функція яка видаляє таймер
    void Start(); //функція яка стартує таймер
    void Stop(); //функція яка зупиняє таймер

private:
    Ui::Timer *ui;
    QTimer *timer;
};

#endif // TIMER_H
