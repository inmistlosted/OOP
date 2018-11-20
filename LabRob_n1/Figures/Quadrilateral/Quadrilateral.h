/**
  Quadrilateral.h
  Purpose: Makes class of Quadrilateral
 */

#ifndef LABROB_N1_QUADRILATERAL_H
#define LABROB_N1_QUADRILATERAL_H

#include "../Distance/Distance.h"

/**
 * Class of Quadrilaterals
 */
class Quadrilateral
{
public:
    /** first diastance */
    Distance d1;
    /** second diastance */
    Distance d2;
    /** third diastance */
    Distance d3;
    /** fourth diastance */
    Distance d4;
    /** diagonal */
    Distance d1_d2;

    /**
     * Constructor of class Quadrilateral
     *
     * @param d1
     * @param d2
     * @param d3
     * @param d4
     * @param d1_d2
     */
    Quadrilateral(Distance d1, Distance d2, Distance d3, Distance d4, Distance d1_d2);

    /**
     * Calculates perimetr of Quadrilateral
     *
     * @return perimetr of Quadrilateral
     */
    double Perimetr();
};

#endif //LABROB_N1_QUADRILATERAL_H
