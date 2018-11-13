#ifndef TIMER_DIAG_H
#define TIMER_DIAG_H

#include <QDialog>
#include <QTime>

namespace Ui {
class Timer_diag;
}

class Timer_diag : public QDialog
{
    Q_OBJECT

public:
    explicit Timer_diag(QWidget *parent = nullptr);
    ~Timer_diag();

public slots:
    int getHours(); //отримує введені години
    int getMin(); //отримує введені хвилини
    int getSec(); //отримує введені секунди

private:
    Ui::Timer_diag *ui;
};

#endif // TIMER_DIAG_H
