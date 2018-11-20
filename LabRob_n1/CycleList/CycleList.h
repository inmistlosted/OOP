/**
  CycleList.h
  Purpose: Makes class of Cycle Lists
 */

#include <iostream>

#ifndef LABROB_N1_CYCLELIST_H
#define LABROB_N1_CYCLELIST_H

using namespace std;

/**
 * class CycleList
 *
 * @tparam T
 */
template<typename T>
class CycleList
{
public:
    /**
     * Constructor of class CycleList
     */
    CycleList();

    /**
     * Destructor of class CycleList
     */
    ~CycleList();

    /**
     * Adds element in the CycleList
     *
     * @param data
     */
    void add(T data);

    /**
     * Gives size of the CycleList
     * @return Size of the CycleList
     */
    int GetSize(){return Size;}

    /**
     * Shows elements of the CycleList
     */
    void Show();

    /**
     * Removes elements from the CycleList
     */
    void remove();

    /**
     * operator overload
     *
     * @param index
     * @return element that's index = @param index
     */
    T& operator[](const int index);

    /**
     * looks for an index of desired element
     *
     * @param element
     * @return index of element
     */
    int find(T element);

    /**
     * Looks for a word "man"
     */
    void find_man();
private:
/**
 * class for Node
 *
 * @tparam U
 */
    template<typename U>
    class Node
    {
    public:
        /** link to the next element */
        Node *pNext;

        /** value of the element */
        U data;

        /**
         * constructor of class Node
         *
         * @param data
         * @param pNext
         */
        Node(U data = U(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    /** Size of the CycleList */
    int Size;

    /** head of the CycleList */
    Node<T> *head;

    /** tail of the CycleList */
    Node<T> *tail;
};

#endif //LABROB_N1_CYCLELIST_H
