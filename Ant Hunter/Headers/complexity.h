/**
  complexity.h
  Purpose: Dialog for choosing a complexity of the game
*/

#ifndef COMPLEXITY_H
#define COMPLEXITY_H

#include <QDialog>

namespace Ui {
class Complexity;
}

class Complexity : public QDialog
{
    Q_OBJECT

public:
    explicit Complexity(QWidget *parent = nullptr);
    ~Complexity();

    /**
     * gives a level of complexity
     *
     * @brief getComplexity
     * @return level of complexity
     */
    int getComplexity();

private:
    Ui::Complexity *ui;
};

#endif // COMPLEXITY_H
