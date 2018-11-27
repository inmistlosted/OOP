/**
  ArrList.cpp
  Purpose: Defines methods of class Triangles
 */

#include "Triangle.h"

//Constructor of class Triangle
Triangle::Triangle(Distance d1, Distance d2, Distance d3)
{
    this->d1 = d1;
    this->d2 = d2;
    this->d3 = d3;
    this->number_of_angles = 3;
    this->type_of_figure = "Triangle";
}

//Checks if a figure is Triangle
bool Triangle::IsTriangle()
{
    double d1_d2 = d1.length() + d2.length();
    double d2_d3 = d2.length() + d3.length();
    double d1_d3 = d1.length() + d3.length();

    if(d1_d2 <= d3.length() || d2_d3 <= d1.length() || d1_d3 <= d2.length())
    {
        cout << "This is not triangle" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

//Calculates perimetr of Triangle
double Triangle::Perimetr()
{
    double p_tr = d1.length() + d2.length() + d3.length();
    return p_tr;
}

//Calculates square of Triangle
double Triangle::Square()
{
    double half_p = Perimetr() / 2;
    double sqr = sqrt(half_p * (half_p - d1.length()) * (half_p - d2.length()) * (half_p - d3.length()));
    return sqr;
}
