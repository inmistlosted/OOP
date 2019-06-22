/**
  Pentagon.h
  Purpose: Makes class of Pentagon
 */

#ifndef LABROB_N1_PENTAGON_H
#define LABROB_N1_PENTAGON_H

#include "../Distance/Distance.h"
#include "../Figure.h"

/**
 * Class of Pentagons
 */
class Pentagon : public Figure
{
public:
    /** first distance */
    Distance d1;
    /** second distance */
    Distance d2;
    /** third distance */
    Distance d3;
    /** fourth distance */
    Distance d4;
    /** fifth distance */
    Distance d5;

    /**
     * Constructor of class Pentagon
     *
     * @param d1
     * @param d2
     * @param d3
     * @param d4
     * @param d5
     */
    Pentagon(Distance d1, Distance d2, Distance d3, Distance d4, Distance d5);

    /**
     * Calculates Perimetr of Pentagon
     *
     * @return Perimetr of Pentagon
     */
    double Perimetr();

    /**
     * Calculates Square of regular Pentagon
     *
     * @return Square of regular Pentagon
     */
    double Sq_Rt();

    /**
     * Calculates Square of common Pentagon
     *
     * @return Square of common Pentagon
     */
    double Sq();
};

#endif //LABROB_N1_PENTAGON_H
