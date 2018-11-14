/**
  alarm.h
  Purpose: Makes alarms work
*/

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

    /**
     * sets received time
     *
     * @brief setTime
     * @param time
     */
    void setTime(const QString& time);

    /**
     * receives time
     *
     * @brief getTime
     * @return
     */
    QString getTime();

public slots:
    /**
     * describes how alarm is working
     *
     * @brief Alrm
     */
    void Alrm();

    /**
     *removes alarm
     *
     * @brief Remove
     */
    void Remove();

private:
    Ui::Alarm *ui;
    QTimer *timer;
};

#endif // ALARM_H
