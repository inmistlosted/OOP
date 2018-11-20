/**
  ArrList.h
  Purpose: Makes class of Array Lists
 */

#include <iostream>
#include <list>
#include <iterator>

#ifndef LABROB_N1_ARRLIST_H
#define LABROB_N1_ARRLIST_H

using namespace std;

const int MAX = 1000;

/**
 * class of ArrayList
 *
 * @tparam T
 */
template<typename T>
class ArrList
{
public:
    /**
     * constructor of class ArrList
     */
    ArrList();

    /**
     * destructor of class ArrList
     */
    ~ArrList();

    /**
     * Pushes an element in the end of the list
     *
     * @param data
     */
    void push_back(T data);

    /**
     * Shows elements of the list
     */
    void Show();

    /**
     * Gives size of the list
     *
     * @return Size of the list
     */
    int get_size(){return size;}

    /**
    * removes an element from the begining of the list
    */
    void remove();

    /**
     * looks for an index of desired element
     *
     * @param element
     * @return index of element
     */
    int find_index(T element);

    /**
     * looks for an element that has input index
     *
     * @param index
     * @return element that's index = @param index
     */
    int find(int index);

    /**
     * looks for first element that is aliquot 3
     */
    void find_aliquot_3();

private:

    /** array with values */
    T val[MAX];

    /** link to next element */
    size_t next;

    /** size of the ArrList */
    int size = 0;

    /** head of the ArrList */
    int head;
};

/**
 * Shows list made with "list" library
 *
 * @param g
 */
void showlist(list<int> g);

#endif //LABROB_N1_ARRLIST_H
