/**
  ArrList.cpp
  Purpose: Defines methods of class Distance
 */

#include "Distance.h"

//Calculates ength of a distance
double Distance::length() // довжина відрізка
{
    double ln = sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
    return ln;
}

//Calculates length of a distance in the second degree
double Distance::length_2() // довжина відрізка в квадраті
{
    double ln_2 =((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y));
    return ln_2;
}

//Checkes if two points of distance aren't the same one
bool Distance::NotSimiliar() //перевірка щоб кінці відрізка не були однією точкою
{
    if(a.x == b.x && a.y == b.y)
    {
        cout << "Points (" << a.x << ", " << a.y << ") and (" << b.x << ", " << b.y << ") are similiar!" << endl;
        return 0;
    }
    else
    {
        return 1;
    }
}