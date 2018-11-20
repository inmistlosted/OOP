/**
  Triangle.h
  Purpose: Makes class of Triangle
 */

#ifndef LABROB_N1_TRIANGLE_H
#define LABROB_N1_TRIANGLE_H

#include "../Distance/Distance.h"

/**
 * Class of Triangle
 */
class Triangle // клас трикутників
{
public:
    /** first distance */
    Distance d1;

    /** second distance */
    Distance d2;

    /** third distance */
    Distance d3;

    /**
     * Constructor of class Triangle
     *
     * @param d1
     * @param d2
     * @param d3
     */
    Triangle(Distance d1, Distance d2, Distance d3);

    /**
     * Checks if a figure is Triangle
     *
     * @return true or false
     */
    bool IsTriangle();

    /**
     * Calculates perimetr of Triangle
     *
     * @return perimetr of Triangle
     */
    double Perimetr();

    /**
     * Calculates square of Triangle
     *
     * @return square of Triangle
     */
    double Square();

};

#endif //LABROB_N1_TRIANGLE_H
