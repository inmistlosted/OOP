/**
  leader.h
  Purpose: widget to add player's name and result in ResultBoard
*/

#ifndef LEADER_H
#define LEADER_H

#include <QWidget>
#include <QString>

namespace Ui {
class Leader;
}

class Leader : public QWidget
{
    Q_OBJECT

public:
    explicit Leader(QWidget *parent = nullptr);
    ~Leader();

    /**
     * sets name of a player
     *
     * @brief Set_Name
     * @param name
     */
    void Set_Name(const QString& name);

    /**
     * sets score what player achived
     *
     * @brief Set_Value
     * @param value
     */
    void Set_Value(const double& value);

private:
    Ui::Leader *ui;
};

#endif // LEADER_H
