#include <iostream>
#include <string>

using namespace std;

template<typename T> //шаблонний клас
class List //клас списку
{
public:
    List();  //конструктор
    ~List(); //деструктор

    void push_back(T data); //додає елемент в кінець списку
    int GetSize(){return Size;} //визначає розмір
    void Show(); //виводить список
    void remove(); //видаляє елемент з початку
    T& operator[](const int index); //перегрузка оператора
    int find(T element); //шукає елемент за значенням
    void find_aliquot_2(); //для пошуку першого елемента кратного 2
private:

    template<typename U>
    class Node //клас вузла
    {
    public:
        Node *pNext; //посилання на наступний елемент
        U data; //значення елемента
        Node(U data = U(), Node *pNext = nullptr) //конструктор
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T> *head; //голова списку
};

template<typename T> //конструктор
List<T>::List() {
    Size = 0;
    head = nullptr;
}

template<typename T> //деструктор
List<T>::~List() {
    while(head)
    {
        remove();
    }
}

template<typename T> //реалізація функції для додавання в кінець
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

template<typename T> //реалізація функції для виводу списка
void List<T>::Show() {
    Node<T> *current = this->head;
    cout << "List: " << endl;
    while(current != nullptr)
    {
        cout << current->data << " ";
        current = current->pNext;
    }

}

template<typename T> //реалізація функції для видаляння елементу
void List<T>::remove() {
    if(head != nullptr)
    {
        Node<T>* newHead = head->pNext;
        delete head;
        Size--;
        head = newHead;
    }
}

template<typename T> //функція для пошуку елемента за індексом
T &List<T>::operator[](const int index) {
    int counter = 0; //лічильник
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

template<typename T> //реалізація функції для пошуку елемента за значенням
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

template<typename T> //реалізація функції для пошуку першого елемента кратного 2
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



template<typename T>
class CycleList //класс циклічного списку
{
public:
    CycleList(); //конструктор
    ~CycleList(); //деструктор

    void add(T data); //додає елемент
    int GetSize(){return Size;} //визначає розмір
    void Show(); //виводить список
    void remove(); //видаляє елемент с початку
    T& operator[](const int index); //перегрузка оператора
    int find(T element); //шукає елемент за значенням
    void find_man(); //функція для пошуку слова man
private:

    template<typename U>
    class Node //клас вузла
    {
    public:
        Node *pNext; //посилання на наступний елемент
        U data; //значення елемента
        Node(U data = U(), Node *pNext = nullptr) //конструктор
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T> *head; //голова списку
    Node<T> *tail; //хвіст списку
};

template<typename T> //конструктор
CycleList<T>::CycleList() {
    Size = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T> //деструктор
CycleList<T>::~CycleList() {
    while(head)
    {
        remove();
    }
}

template<typename T> //реалізація функції для додавання нового елемента
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

template<typename T> //реалізація функції для виводу списка
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

template<typename T> //реалізація функції для видаляння елементу
void CycleList<T>::remove() {
    if(head != nullptr)
    {
        Node<T>* newHead = head->pNext;
        delete head;
        Size--;
        head = newHead;
    }
}

template<typename T> //функція для пошуку елемента за індексом
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

template<typename T> //реалізація функції для пошуку елемента за значенням
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

template<typename T> //реалізація функціЇ для пошуку слова man
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


int main() {
    int l, index, value;
    string word;
    cout << "What List do you want to make: List(1) or Cycle List(2)? ";
    cin >> l;
    cout << endl;

    if(l == 1)
    {
        List<int> list;
        list.push_back(23);
        list.push_back(24);
        list.push_back(32);
        list.push_back(65);
        list.push_back(96);
        list.push_back(18);
        list.push_back(50);

        list.Show();
        cout << endl << "Size of List: " << list.GetSize() << endl;
        cout << "Enter index of an element, which you want to find: ";
        cin >> index;
        cout << "Element with index " << index << " is " << list[index] << endl;
        cout << "Enter value of an element, which you want to find: ";
        cin >> value;
        cout << "Element with value " << value << " has index " << list.find(value) << endl;
        list.find_aliquot_2();
    }
    else
    {
        CycleList<string> lst;
        lst.add("Elon");
        lst.add("Musk");
        lst.add("is");
        lst.add("the");
        lst.add("greatest");
        lst.add("man");
        lst.add("alive");

        lst.Show();
        cout << endl << "Size of List: " << lst.GetSize() << endl;
        cout << "Enter index of an element, which you want to find: ";
        cin >> index;
        cout << "Element with index " << index << " is \"" << lst[index] << "\"" << endl;
        cout << "Enter value of an element, which you want to find(a word from the sentence): ";
        cin >> word;
        cout << "Element with value \"" << word << "\" has index " << lst.find(word) << endl;
        lst.find_man();
    }
    return 0;
}