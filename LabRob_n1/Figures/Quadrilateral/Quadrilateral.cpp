/**
  Quadrilateral.cpp
  Purpose: Defines methods of class Quadrilateral
 */

#include "Quadrilateral.h"

//Constructor of class Quadrilateral
Quadrilateral::Quadrilateral(Distance d1, Distance d2, Distance d3, Distance d4, Distance d1_d2)
{
    this->d1 = d1;
    this->d2 = d2;
    this->d3 = d3;
    this->d4 = d4;
    this->d1_d2 = d1_d2;
    this->type_of_figure = "Quadrilateral";
    this->number_of_angles = 4;
}

//Calculates perimetr of Quadrilateral
double Quadrilateral::Perimetr() // периметр
{
    double p_qd = d1.length() + d2.length() + d3.length() + d4.length();
    return p_qd;
}