/**
  ArrList.cpp
  Purpose: Defines methods of class Type_of_Tri
 */

#include "Types_of_Tri.h"

//Checks if Triangle is Rectangular
bool Type_of_Tri::IsRect()
{
    double d1_2 = d1.length_2();
    double d2_2 = d2.length_2();
    double d3_2 = d3.length_2();
    double ad1_d2 = d1_2 + d2_2;
    double ad1_d3 = d1_2 + d3_2;
    double ad2_d3 = d2_2 + d3_2;
    if(ad1_d2 == d3_2 || ad2_d3 == d1_2 || ad1_d3 == d2_2)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

//Shows that Triangle is Rectangular
void Type_of_Tri::Show_Rect()
{
    cout << "This triangle is Rectangular" << endl;
}

//Checks if Triangle is Equal
bool Type_of_Tri::IsEqual()
{
    if(d1.length() == d2.length() && d1.length() == d3.length() && d2.length() == d3.length())
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

//Checks if Triangle is Isosceles
bool Type_of_Tri::IsIsos()
{
    if(d1.length() == d2.length() || d1.length() == d3.length() || d2.length() == d3.length())
    {
        if(!IsEqual())
        {
            cout << "This triangle is Equilateral" << endl;
            return 1;
        }
        else {
            cout << "This triangle is Isosceles" << endl;
            return 0;
        }
    }
    else
    {
        return 1;
    }

}