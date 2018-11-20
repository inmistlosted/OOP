/**
  Type_of_Pent.h
  Purpose: Makes class of Type_of_Pent
 */

#ifndef LABROB_N1_TYPE_OF_PENT_H
#define LABROB_N1_TYPE_OF_PENT_H

#include "../Pentagon.h"

/**
 * class of Types of Pentagons
 */
class Type_of_Pent : public Pentagon
{
public:
    /**
     * Constructor of class Type_of_Pent
     *
     * @param d1
     * @param d2
     * @param d3
     * @param d4
     * @param d5
     */
    Type_of_Pent(Distance d1, Distance d2, Distance d3, Distance d4, Distance d5) : Pentagon(d1,d2,d3,d4,d5) // конструктор
    {
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
        this->d4 = d4;
        this->d5 = d5;
    }

    /**
     * Checks if Pentagon is Regular
     *
     * @return true or false
     */
    bool IsRightPent();
};

#endif //LABROB_N1_TYPE_OF_PENT_H
