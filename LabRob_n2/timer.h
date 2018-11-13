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

    void setHours(const int& hours);
    void setMin(const int& mins);
    void setSec(const int& secs);

public slots:
    void Tmr();
    void Remove();
    void Start();
    void Stop();

private:
    Ui::Timer *ui;
    QTimer *timer;
};

#endif // TIMER_H
