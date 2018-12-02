#ifndef LEADERS_H
#define LEADERS_H

#include <QDialog>

namespace Ui {
class Leaders;
}

class Leaders : public QDialog
{
    Q_OBJECT

public:
    explicit Leaders(QWidget *parent = nullptr);
    ~Leaders();

private:
    Ui::Leaders *ui;
};

#endif // LEADERS_H
