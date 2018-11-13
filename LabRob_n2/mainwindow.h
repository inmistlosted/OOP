#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>
#include <QVector>
#include <QMessageBox>

#include "alarm_diag.h"
#include "alarm.h"
#include "timer_diag.h"
#include "timer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void Open_alarm();
    void Open_timer();

private:
    Ui::MainWindow *ui;
    QTime *time;
    Alarm_diag *alarm_diag;
    Alarm *alarm;
    Timer_diag *tmr_diag;
    Timer *tmr;

private slots:
    void Add_Alarm();
    void Add_Timer();
};

#endif // MAINWINDOW_H
