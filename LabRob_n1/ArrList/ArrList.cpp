/**
  ArrList.cpp
  Purpose: Defines methods of class ArrList
 */

#include "ArrList.h"

//constructor of class ArrList
template<typename T>
ArrList<T>::ArrList() {
    head = 0;
    next = 0;
}

//destructor of class ArrList
template<typename T>
ArrList<T>::~ArrList() {
    while(size != 0)
    {
        remove();
    }
}

//Pushes an element in the end of the list
template<typename T>
void ArrList<T>::push_back(T data) {
    val[next] = data;
    next++;
    size++;
}

//Shows elements of the list
template<typename T>
void ArrList<T>::Show() {
    int i = head;
    cout << "List: " << endl;
    while(i != size)
    {
        cout << val[i] << " ";
        i++;
    }
}

//removes an element from the begining of the list
template<typename T>
void ArrList<T>::remove() {
    for(int i = head; i < size; i++)
    {
        val[i] = val[i + 1];
    }
    size--;
}

//looks for an index of desired element
template<typename T>
int ArrList<T>::find_index(T element) {
    int i = head;
    while(i != size)
    {
        if(val[i] == element)
        {
            return i;
        }
        i++;
    }
}

//looks for an element that has input index
template<typename T>
int ArrList<T>::find(int index) {
    return val[index];
}

//looks for first element that is aliquot 3
template<typename T>
void ArrList<T>::find_aliquot_3() {
    int i = head;
    while(i != size)
    {
        if(val[i] % 3 == 0)
        {
            cout << val[i] << " is first to aliquot 3, it's index = " << i << endl;
            break;
        }
        i++;
    }
}

//Shows list made with "list" library
void showlist(list<int> g)
{
    list<int>::iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}