/**
  ArrList.cpp
  Purpose: Defines methods of class Line
 */

#include "Line.h"

//Constructor of class Line
Line::Line(Point a, Point b, Point c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

//Checks if 3 Points aren't on the same line
bool Line::OneLine()
{
    double k = (a.y - b.y) / (a.x - b.x);
    double l = b.y - k * b.x;
    if(c.y == k * c.x + l)
    {
        cout << "Points (" << a.x << ", " << a.y << "), ("<< b.x << ", " << b.y << "), (" << c.x << ", " << c.y << ") are on the same line!" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}