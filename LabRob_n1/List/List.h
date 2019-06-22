/**
  List.h
  Purpose: Makes class of Lists
 */

#include <iostream>

#ifndef LABROB_N1_LIST_H
#define LABROB_N1_LIST_H

using namespace std;

/**
 * class List
 *
 * @tparam T
 */
template<typename T>
class List
{
public:
    /**
     * Constructor of class List
     */
    List();

    /**
     * Destructor of class List
     */
    ~List();

    /**
     * Pushes an element in the end of the list
     *
     * @param data
     */
    void push_back(T data);

    /**
     * Gives size of the list
     *
     * @return Size of the list
     */
    int GetSize(){return Size;}

    /**
     * Shows elements of the list
     */
    void Show();

    /**
     * removes an element from the beggining of the list
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
     * looks for first element that is aliquot 2
     */
    void find_aliquot_2();

    /**
     * checks if there is element 'a' in the List
     *
     * @return true or false
     */
    bool find_a();
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
        /** link to next element */
        Node *pNext;

        /** value of element */
        U data;

        /**
         * constructor of class Node
         *
         * @param data
         * @param pNext
         */
        Node(U data = U(), Node *pNext = nullptr) //конструктор
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    /** size of the list */
    int Size;

    /** head of the list */
    Node<T> *head;
};

#endif //LABROB_N1_LIST_H
