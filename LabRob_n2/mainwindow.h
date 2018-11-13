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

    //публічні слоти які буду використовувати
public slots:
    void Open_alarm(); //виклик вікна для добавлення будильника
    void Open_timer(); //виклик вікна для добавлення таймера

    //об'єкти які знадобляться
private:
    Ui::MainWindow *ui;
    QTime *time;
    Alarm_diag *alarm_diag;
    Alarm *alarm;
    Timer_diag *tmr_diag;
    Timer *tmr;

    //приватні слоти які буду використовувати
private slots:
    void Add_Alarm(); //добавлення будильника
    void Add_Timer(); //добавлення таймера
};

#endif // MAINWINDOW_H
