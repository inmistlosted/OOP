/**
  Figure.h
  Purpose: Defines class of Figure
 */

#ifndef LABROB_N1_FIGURE_H
#define LABROB_N1_FIGURE_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

/**
 * Class of Figure
 */
class Figure
{
public:
    /** name of figure */
    string type_of_figure;
    /** Perimetr of this figure */
    double P;
    /** Square of this figure */
    double S;
    /** Number of angles */
    int number_of_angles;
};

/**
 * shows the list of geometric figures
 *
 * @param figures
 */
void showlist(list<Figure> figures);

#endif //LABROB_N1_FIGURE_H
