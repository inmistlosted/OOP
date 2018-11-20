/**
  Quad_Sq.h
  Purpose: Makes class of Quad_Sq
 */

#ifndef LABROB_N1_QUAD_SQ_H
#define LABROB_N1_QUAD_SQ_H

#include "../Quadrilateral.h"

/**
 * Class for Squares of Quadrilaterals
 */
class Quad_Sq : public Quadrilateral
{
public:
    /**
     * Constructor of class Quad_Sq
     *
     * @param d1
     * @param d2
     * @param d3
     * @param d4
     * @param d1_d2
     */
    Quad_Sq(Distance d1, Distance d2, Distance d3, Distance d4, Distance d1_d2) : Quadrilateral(d1,d2,d3,d4,d1_d2)
    {
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
        this->d4 = d4;
        this->d1_d2 = d1_d2;
    }

    /**
     * Calculates common Square
     *
     * @return common Square
     */
    double Square();

    /**
     * Calculates Square of Trapezium first ocassion(First and Third distances are bases)
     *
     * @return Square
     */
    double S_TRap1();

    /**
     * Calculates Square of Trapezium second ocassion(First and Third distances are bases)
     *
     * @return Square
     */
    double S_TRap2();

    /**
     * Calculates Square of Trapezium first ocassion(Second and Fourth distances are bases)
     *
     * @return Square
     */
    double S_TRap1_1();

    /**
     * Calculates Square of Trapezium second ocassion(Second and Fourth distances are bases)
     *
     * @return Square
     */
    double S_TRap2_2();

    /**
     * Calculates Square of SQuare
     *
     * @return Square of SQuare
     */
    double S_Sq();


    /**
     * Calculates Square of Rectangle
     *
     * @return Square of Rectangle
     */
    double S_Rect();
};

#endif //LABROB_N1_QUAD_SQ_H
