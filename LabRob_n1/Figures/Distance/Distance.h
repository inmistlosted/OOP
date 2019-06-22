/**
  Distance.h
  Purpose: Makes class of Distance
 */


#ifndef LABROB_N1_DISTANCE_H
#define LABROB_N1_DISTANCE_H

#include <iostream>
#include <cmath>
#include "../Point/Point.h"

using namespace std;

/**
 * Class of Distance
 */
class Distance  //клас відрізка
{
public:
    /** first point of distance */
    Point a;
    /** second point of distance */
    Point b;

    /**
     * Calculates length of a distance
     *
     * @return length of a distance
     */
    double length();

    /**
     * Calculates length of a distance in the second degree
     *
     * @return length of a distance in the second degree
     */
    double length_2();

    /**
     * Checkes if two points of distance aren't the same one
     *
     * @return true or false
     */
    bool NotSimiliar();
};

#endif //LABROB_N1_DISTANCE_H
