/**
  Types_of_Tri.h
  Purpose: Makes class of Type_of_Tri
 */


#ifndef LABROB_N1_TYPES_OF_TRI_H
#define LABROB_N1_TYPES_OF_TRI_H

#include "../Triangle.h"

/**
 * Class for Types of Triangles
 */
class Type_of_Tri : public Triangle
{
public:
    /**
     * Constructor of class Type_of_Tri
     *
     * @param d1
     * @param d2
     * @param d3
     */
    Type_of_Tri(Distance d1, Distance d2, Distance d3) : Triangle(d1,d2,d3)
    {
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
    }

    /**
     * Checks if Triangle is Rectangular
     *
     * @return true or false
     */
    bool IsRect();

    /**
     * Shows that Triangle is Rectangular
     */
    void Show_Rect();

    /**
     * Checks if Triangle is Equal
     *
     * @return true or false
     */
    bool IsEqual();


    /**
     * Checks if Triangle is Isosceles
     *
     * @return true or false
     */
    bool IsIsos();
};

#endif //LABROB_N1_TYPES_OF_TRI_H
