/**
  mainwindow.h
  Purpose: shows and operates with timers and alarms

  @author inmistlosted
  @version 1.0
*/


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
    /**
     * calls a dialog window for inputing time for alarms
     *
     * @brief Open_alarm
     */
    void Open_alarm();

    /**
     * calls a dialog window for inputing time for timers
     *
     * @brief Open_timer
     */
    void Open_timer();

private:
    Ui::MainWindow *ui;
    QTime *time;
    Alarm_diag *alarm_diag;
    Alarm *alarm;
    Timer_diag *tmr_diag;
    Timer *tmr;


private slots:
    /**
     * adds alarm
     *
     * @brief Add_Alarm
     */
    void Add_Alarm(); //добавлення будильника

    /**
     * adds timer
     *
     * @brief Add_Timer
     */
    void Add_Timer(); //добавлення таймера
};

#endif // MAINWINDOW_H