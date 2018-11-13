#ifndef ALARM_DIAG_H
#define ALARM_DIAG_H

#include <QDialog>
#include <QTime>

namespace Ui {
class Alarm_diag;
}

class Alarm_diag : public QDialog
{
    Q_OBJECT

public:
    explicit Alarm_diag(QWidget *parent = nullptr);
    ~Alarm_diag();
public slots:
    int getHours(); //отримує введені години
    int getMin(); //отримує введені хвилини
    int getSec(); //отримує введені секунди
    QTime alrm(); //повертає введений час

private:
    Ui::Alarm_diag *ui;
};

#endif // ALARM_DIAG_H
