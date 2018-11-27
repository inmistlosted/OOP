/**
  Pentagon.cpp
  Purpose: Defines methods of class Pentagon
 */

#include "Pentagon.h"

//Constructor of class Pentagon
Pentagon::Pentagon(Distance d1, Distance d2, Distance d3, Distance d4, Distance d5)
{
    this->d1 = d1;
    this->d2 = d2;
    this->d3 = d3;
    this->d4 = d4;
    this->d5 = d5;
    this->number_of_angles = 5;
    this->type_of_figure = "Pentagon";
}

//Calculates Perimetr of Pentagon
double Pentagon::Perimetr()
{
    double p_qd = d1.length() + d2.length() + d3.length() + d4.length() + d5.length();
    return p_qd;
}

//Calculates Square of regular Pentagon
double Pentagon::Sq_Rt()
{
    double s = d1.length_2() * sqrt(25 + 10 * sqrt(5)) / 4;
    return s;
}

//Calculates Square of common Pentagon
double Pentagon::Sq()
{
    double a = d1.length() / 2 / tan(180 / 5);
    double s = Perimetr() * a / 2;
    return s;
}
