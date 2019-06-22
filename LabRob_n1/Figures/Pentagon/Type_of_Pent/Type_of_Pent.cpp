/**
  Type_of_Pent.cpp
  Purpose: Defines methods of class Type_of_Pent
 */

#include "Type_of_Pent.h"

//Checks if Pentagon is Regular
bool Type_of_Pent::IsRightPent()
{
    if(d1.length() == d2.length() && d2.length() == d3.length() && d3.length() == d4.length() && d4.length() == d5.length())
    {
        cout << "This is the Right Pentagon" << endl;
        cout << "Square ABCDE = " << Sq_Rt() << endl;
        return 0;
    }
    else
    {
        cout << "Square ABCDE = " << Sq() << endl;
        return 1;
    }
}