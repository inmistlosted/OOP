/**
  Quad_Sq.cpp
  Purpose: Defines methods of class Quad_Sq
 */

#include "Quad_Sq.h"

//Calculates common Square
double Quad_Sq::Square()
{
    double half_p = Perimetr() / 2;
    double sqr = sqrt((half_p - d1.length()) * (half_p - d2.length()) * (half_p - d3.length()) * (half_p - d4.length()));
    return sqr;
}

//Calculates Square of Trapezium first ocassion(First and Third distances are bases)
double Quad_Sq::S_TRap1()
{
    double a = d2.length();
    double b = d4.length();
    double c = d1.length();
    double d = d3.length();
    double s = (a + b) / 2 * sqrt(pow(c,2) - pow((pow(a - b,2) + c * c - d * d)/ 2 / (a - b),2));
    return s;
}

//Calculates Square of Trapezium second ocassion(First and Third distances are bases)
double Quad_Sq::S_TRap2()
{
    double a = d2.length();
    double b = d4.length();
    double c = d1.length();
    double d = d3.length();
    double half_p = Perimetr() / 2;
    double s = (a+b)/(a-b) * sqrt((half_p - a) * (half_p - b) * (half_p - a - c) * (half_p - a - d));
    return s;
}

//Calculates Square of Trapezium first ocassion(Second and Fourth distances are bases)
double Quad_Sq::S_TRap1_1()
{
    double a = d1.length();
    double b = d3.length();
    double c = d2.length();
    double d = d4.length();
    double s = (a + b) / 2 * sqrt(pow(c,2) - pow((pow(a - b,2) + c * c - d * d)/ 2 / (a - b),2));
    return s;
}

//Calculates Square of Trapezium second ocassion(Second and Fourth distances are bases)
double Quad_Sq::S_TRap2_2()
{
    double a = d1.length();
    double b = d3.length();
    double c = d2.length();
    double d = d4.length();
    double half_p = Perimetr() / 2;
    double s = (a+b)/(a-b) * sqrt((half_p - a) * (half_p - b) * (half_p - a - c) * (half_p - a - d));
    return s;
}

//Calculates Square of SQuare
double Quad_Sq::S_Sq()
{
    double s = d1.length() * d1.length();
    return s;
}

//Calculates Square of Rectangle
double Quad_Sq::S_Rect()
{
    double s = d1.length() * d2.length();
    return s;
}