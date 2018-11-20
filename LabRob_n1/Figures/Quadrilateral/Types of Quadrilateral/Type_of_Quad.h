/**
  Type_of_Quad.h
  Purpose: Makes class of Type_of_Quad
 */


#ifndef LABROB_N1_TYPE_OF_QUAD_H
#define LABROB_N1_TYPE_OF_QUAD_H

#include "../../Triangle/Types of Triangle/Types_of_Tri.h"
#include "../Squares of Quadrilateral/Quad_Sq.h"

/**
 * Class of Types of Quadrilaterals
 */
class Type_of_Quad : public Quad_Sq
{
public:
    /**
     * Constructor of class Type_of_Quad
     *
     * @param d1
     * @param d2
     * @param d3
     * @param d4
     * @param d1_d2
     */
    Type_of_Quad(Distance d1, Distance d2, Distance d3, Distance d4, Distance d1_d2) : Quad_Sq(d1,d2,d3,d4,d1_d2)//конструктор
    {
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
        this->d4 = d4;
        this->d1_d2 = d1_d2;
    }

    /**
     * Checks if Quadrilateral is Square
     *
     * @return true or false
     */
    bool IsSquare();

    /**
     * Checks if Quadrilateral is Rhombus
     *
     * @return true or false
     */
    bool IsRhombus();

    /**
     * Checks if Quadrilateral is Rectangle
     *
     * @return true or false
     */
    bool IsRectangle();

    /**
     * Checks if Quadrilateral is Parallelogram
     *
     * @return true or false
     */
    bool IsParallelogram();

    /**
     * Checks if Quadrilateral is Trapezium
     *
     * @return true or false
     */
    bool IsTrapeze();
};

#endif //LABROB_N1_TYPE_OF_QUAD_H
