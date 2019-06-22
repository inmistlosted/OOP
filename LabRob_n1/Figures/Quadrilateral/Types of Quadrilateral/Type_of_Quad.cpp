/**
  Type_of_Quad.cpp
  Purpose: Defines methods of class Type_of_Quad
 */

#include "Type_of_Quad.h"


//Checks if Quadrilateral is Square
bool Type_of_Quad::IsSquare()
{
    Type_of_Tri d1d2(d1,d2,d1_d2);
    if(d1.length() == d2.length() && d2.length() == d3.length() && d3.length() == d4.length() && d1d2.IsRect() == true)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Checks if Quadrilateral is Rhombus
bool Type_of_Quad::IsRhombus()
{
    if(d1.length() == d2.length() && d2.length() == d3.length() && d3.length() == d4.length())
    {
        if(IsSquare() == true)
        {
            cout << "This Quadrilateral is Square" << endl;
            cout << "Square: " << S_Sq() << endl;
            return 1;
        }
        else
        {
            cout << "This Quadrilateral is Rhombus" << endl;
            cout << "Square: " << Square() << endl;
            return 0;
        }
    }
    else
    {
        return 1;
    }
}

//Checks if Quadrilateral is Rectangle
bool Type_of_Quad::IsRectangle()
{
    Type_of_Tri d1d2(d1,d2,d1_d2);
    if(d1.length() == d3.length() && d2.length() == d4.length() && d1.length() != d2.length() && d1d2.IsRect() == true)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Checks if Quadrilateral is Parallelogram
bool Type_of_Quad::IsParallelogram() //перевірка чи є паралелограмом
{
    Type_of_Tri d1d2(d1,d2,d1_d2);
    if(d1.length() == d3.length() && d2.length() == d4.length() && d1.length() != d2.length())
    {
        if(IsRectangle())
        {
            cout << "This Quadrilateral is Rectangular" << endl;
            cout << "Square: " << S_Rect() << endl;
            return 1;
        }
        else
        {
            cout << "This Quadrilateral is Parallelogram" << endl;
            cout << "Square: " << Square() << endl;
            return 0;
        }
    }
    else
    {
        return 1;
    }
}

//Checks if Quadrilateral is Trapezium
bool Type_of_Quad::IsTrapeze() //перевірка чи є трапецією
{
    if(S_TRap1() == S_TRap2())
    {
        cout << "This is Trapeze" << endl;
        cout << "Square: " << S_TRap1() << endl;
        return 0;
    }
    else if(S_TRap1_1() == S_TRap2_2())
    {
        cout << "This is Trapeze" << endl;
        cout << "Square: " << S_TRap1() << endl;
        return 0;
    }
    else
    {
        return 1;
    }
}