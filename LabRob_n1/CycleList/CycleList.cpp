/**
  CycleList.cpp
  Purpose: Defines methods of class CycleList
 */

#include "CycleList.h"

//Constructor of class CycleList
template<typename T>
CycleList<T>::CycleList() {
    Size = 0;
    head = nullptr;
    tail = nullptr;
}

//Destructor of class CycleList
template<typename T>
CycleList<T>::~CycleList() {
    while(head)
    {
        remove();
    }
}

//Adds element in the CycleList
template<typename T>
void CycleList<T>::add(T data) {
    Node<T> *current = new Node<T>;
    current->pNext = head;
    current->data = data;

    if(head != nullptr)
    {
        tail->pNext = current;
        tail = current;
    }
    else
    {
        head = tail = current;
    }
    Size++;
}

//Shows elements of the CycleList
template<typename T>
void CycleList<T>::Show() {
    Node<T> *currHead = head;
    cout << "List: " << endl;
    int current = Size;
    while(current != 0)
    {
        cout << currHead->data << " ";
        currHead = currHead->pNext;
        current--;
    }
}

//Removes elements from the CycleList
template<typename T>
void CycleList<T>::remove() {
    if(head != nullptr)
    {
        Node<T>* newHead = head->pNext;
        delete head;
        Size--;
        head = newHead;
    }
}

//operator overload
template<typename T>
T &CycleList<T>::operator[](const int index) {
    int counter = 0;
    Node<T> *current = this->head;
    while(current != nullptr)
    {
        if(counter == index)
        {
            return current->data;
        }
        else {
            current = current->pNext;
            counter++;
        }
    }
}

//looks for an index of desired element
template<typename T>
int CycleList<T>::find(T element) {
    int index = 0;
    int arr[10];
    Node<T> *current = this->head;
    while(current != nullptr)
    {
        if (current->data == element) {
            return index;
        } else {
            current = current->pNext;
            index++;
        }
    }

}

//Looks for a word "man"
template<typename T>
void CycleList<T>::find_man() {
    int index = 0;
    Node<T> *current = this->head;
    while(current != nullptr)
    {
        if(current->data == "man")
        {
            cout << "The first word \"man\" has index: " << index << endl;
            break;
        }
        else
        {
            current = current->pNext;
            index++;
        }
    }
}