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

    void setTime(const QString& time);
    QString getTime();

public slots:
    void Alrm();
    void Remove();

private:
    Ui::Alarm *ui;
    QTimer *timer;
};

#endif // ALARM_H
