/**
  Line.h
  Purpose: Makes class of Line
 */

#ifndef LABROB_N1_LINE_H
#define LABROB_N1_LINE_H

#include "../Distance/Distance.h"

/**
 * Class of Line to check if 3 Points aren't on the same line
 */
class Line : public Distance
{
public:
    /** first Point */
    Point a;
    /** second Point */
    Point b;
    /** Third Point */
    Point c;

    /**
     * Constructor of class Line
     *
     * @param a
     * @param b
     * @param c
     */
    Line(Point a, Point b, Point c);

    /**
     * Checks if 3 Points aren't on the same line
     *
     * @return true or false
     */
    bool OneLine();
};


#endif //LABROB_N1_LINE_H
