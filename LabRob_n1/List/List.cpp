/**
  CycleList.cpp
  Purpose: Defines methods of class List
 */


#include "List.h"

//Constructor of class List
template<typename T>
List<T>::List() {
    Size = 0;
    head = nullptr;
}

//Destructor of class List
template<typename T>
List<T>::~List() {
    while(head)
    {
        remove();
    }
}

//Pushes an element in the end of the list
template<typename T>
void List<T>::push_back(T data) {
    if(head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;

        while(current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

//Shows elements of the list
template<typename T>
void List<T>::Show() {
    Node<T> *current = this->head;
    cout << "List: " << endl;
    while(current != nullptr)
    {
        cout << current->data << " ";
        current = current->pNext;
    }

}

//removes an element from the beggining of the list
template<typename T>
void List<T>::remove() {
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
T &List<T>::operator[](const int index) {
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
int List<T>::find(T element) {
    int index = 0;
    Node<T> *current = this->head;
    while(current != nullptr)
    {
        if(current->data == element)
        {
            return index;
        }
        else
        {
            current = current->pNext;
            index++;
        }
    }

}

//looks for first element that is aliquot 2
template<typename T>
void List<T>::find_aliquot_2() {
    int index = 0;
    Node<T> *current = this->head;
    while(current != nullptr)
    {
        if(current->data % 2 == 0)
        {
            cout << current->data << " is first to aliquot 2, it's index = " << index << endl;
            break;
        }
        else
        {
            current = current->pNext;
            index++;
        }
    }
}

template<typename  T>
bool List<T>::find_a()
{
    int index = 0;
    Node<T> *current = this->head;
    while(current != nullptr)
    {
        if(current->data == 'a')
        {
            cout << " There is 'a' in the List, it's index = " << index << endl;
            return true;
        }
        else
        {
            current = current->pNext;
            index++;
        }
    }
    return false;
}