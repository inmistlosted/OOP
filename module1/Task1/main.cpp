#include <iostream>
#include <zconf.h>
#include <ctime>


using namespace std;


class Network_of_servers //клас мережі серверів
{
public:
    Network_of_servers();  //конструктор
    ~Network_of_servers(); //деструктор

    void add_server(int prog_numb, int send_speed); //додає новий сервер у мережу
    void send_message(double size, string type, int sender, int receiver); //процес стрворення і передачі повідомлення в мережі
    void make_list(); //створює список серверів через які найчастіше проходили повідомлення
    void show_list(); //виводить цей список
private:

    class Programe //клас програми
    {
    public:
        int program_type; //тип програми(1 - тільки отримує повідомлення, 2 - отримує і передає, 3 - надсилає з періодичністю 3 сек,
    };                    //4 - надсилає з випадковою періодичністю, 5 - надсилає повідомлення лише типів apk i doc)


    class Server //клас серверу
    {
    public:
        Server *Next; //вказівник на наступний сервер
        Server *Prev; //вказівник на попередній сервер
        int number; //порядковий номер серверу
        int used = 0; //зміння для підрахунку скільки разів повідомлення пройшло через сервер
        Programe running_pr; //програма, яка запущена на сервері
        int send_speed; //швидкість передачі повідомлень між серверами

        Server(Server *Next = nullptr, Server *Prev = nullptr) //конструктор
        {
            this->Next = Next;
            this->Prev = Prev;
        }

        int Get_pr_numb()
        {
            return running_pr.program_type;
        }

        void Set_pr_numb(int n)
        {
            running_pr.program_type = n;
        }
    };
    int Size; //розмір мережі
    Server *first, *last; //вказівники на перший і останній сервери

    class Message //клас повідомлення
    {
    public:
        Server *ReceiverS; //вказівник на отримуючий сервер
        Server *SenderS; //вказівник на відправляючий сервер
        int prog_nS; //тип програми відправника
        int ptod_nR; //тип програми отримувача
        double size; //розмір повідомлення
        string type; //тип повідомлення
        Message(double size, string type) //конструктор
        {

            this->size = size;
            this->type = type;
        }
    };

    class List //клас списку
    {
    public:
        List(){ //конструктор
            Size = 0;
            head = nullptr;
        }
        ~List(){  //деструктор
            while(head)
            {
                remove();
            }
        }

        void push_back(int data, int number) { //додає елемент в кінець списку
            if(head == nullptr)
            {
                head = new Node(data, number);
            }
            else
            {
                Node *current = this->head;

                while(current->pNext != nullptr)
                {
                    current = current->pNext;
                }
                current->pNext = new Node(data, number);
            }
            Size++;
        }

        int GetSize(){return Size;} //визначає розмір

        void remove(){  //видаляє елемент з початку списка
            if(head != nullptr)
            {
                Node* newHead = head->pNext;
                delete head;
                Size--;
                head = newHead;
            }
        }
        void Show(){  //виводить список
            Node *current = this->head;
            cout << "List: " << endl;
            while(current != nullptr)
            {
                cout << current->number << " - " << current->data << endl;
                current = current->pNext;
            }

        }

        void sort() //сортує список за кількістю повідомлень, які пройшли через сервер
        {
            Node *left = this->head;
            Node *right = head->pNext;

            Node *current = new Node;

            while(left->pNext != nullptr){
                while(right != nullptr)
                {
                    if((left->data) < (right->data))
                    {
                        current->data = left->data;
                        current->number = left->number;
                        left->data = right->data;
                        left->number = right->number;
                        right->data = current->data;
                        right->number = current->number;
                    }
                    right = right->pNext;
                }
                left = left->pNext;
                right = left->pNext;
            }
        }

    private:
        class Node //клас вузла
        {
        public:
            Node *pNext; //посилання на наступний елемент
            int data; //значення елемента
            int number; //номер сервера
            Node(int data = 0,int number = 0, Node *pNext = nullptr) //конструктор
            {
                this->number = number;
                this->data = data;
                this->pNext = pNext;
            }
        };
        int Size;
        Node *head; //голова списку
    };
};

//конструктор
Network_of_servers::Network_of_servers() {
    Size = 0;
    first = nullptr;
    last = nullptr;
}

//деструктор
Network_of_servers::~Network_of_servers() {
    while(first)
    {
        last = first->Next;
        delete first;
        first = last;
    }
}

//додає новий сервер у мережу
void Network_of_servers::add_server(int prog_numb, int send_speed) {
    Server *curr = new Server;
    curr->Next = nullptr;
    curr->Set_pr_numb(prog_numb);
    curr->send_speed = send_speed;
    curr->number = Size + 1;

    if(first != nullptr)
    {
        curr->Prev = last;
        last->Next = curr;
        last = curr;
    }
    else
    {
        curr->Prev = nullptr;
        first = last = curr;
    }
    Size++;
}

//процес стрворення і передачі повідомлення в мережі
void Network_of_servers::send_message(double size, string type,int sender, int receiver) {
    int counter1 = 1;
    Server *current = this->first; //current зпочатку дорівнює першому серверу в мережі
    Message *msg = new Message(size, type); //створення нового повідомлення

    while (current != nullptr) {
        if (counter1 == sender) {
            msg->prog_nS = current->Get_pr_numb();
            current = current->Next;
            counter1++;

        } else if (counter1 == sender + 1) { //записуємо вказівник на сервер-відправник та номер програми-відправника у повідомлення
            msg->SenderS = current->Prev;
            break;
        } else {

            current = current->Next;
            counter1++;
        }
    }

    //у випадку, якщо номер сервера-отримувача більше номера сервера-відправника
    if (receiver > sender) {
        int counter2 = 1;
        Server *temp = this->first;
        while (counter2 != sender) {
            temp = temp->Next;
            counter2++;
        }
        while (temp != nullptr) {
            if (counter2 == receiver - 1) {
                msg->ReceiverS = temp->Next;
                sleep(msg->size * 1); //для встановлення скільки часу повідомлення йде до сусіднього сервера
                sleep(temp->send_speed);
                temp = temp->Next;
                counter2++;
            } else if (counter2 == receiver) {
                msg->ptod_nR = temp->Get_pr_numb();
                break;
            } else {
                if (temp->Get_pr_numb() == 1) { //1 тип програми
                    temp->used = temp->used + 1;
                    break;
                } else if (temp->Get_pr_numb() == 2) { //2 тип програми
                    sleep(temp->send_speed);
                    sleep(msg->size * 1);
                    temp = temp->Next;
                    counter2++;
                    temp->used = temp->used + 1;

                } else if (temp->Get_pr_numb() == 3) { //3 тип програми
                    sleep(temp->send_speed);
                    sleep(msg->size * 1);
                    sleep(3);
                    temp = temp->Next;
                    counter2++;
                    temp->used = temp->used + 1;
                } else if (temp->Get_pr_numb() == 4) { //4 тип програми
                    sleep(temp->send_speed);
                    sleep(msg->size * 1);
                    srand(time(0));
                    sleep(1 + rand() % 10);
                    temp = temp->Next;
                    counter2++;
                    temp->used = temp->used + 1;
                } else if (temp->Get_pr_numb() == 5) { //5 тип програми
                    if (msg->type == "apk" || msg->type == "doc") {
                        sleep(temp->send_speed);
                        sleep(msg->size * 1);
                        temp = temp->Next;
                        counter2++;
                        temp->used = temp->used + 1;
                    } else {
                        temp->used = temp->used + 1;
                        sleep(temp->send_speed);
                        sleep(msg->size * 1);
                        break;
                    }
                }
            }
        }
    }

        //у випадку, якщо номер сервера-отримувача менше номера сервера-відправника
    else {
        int counter2 = Size;
        Server *temp = this->last;
        while (counter2 != sender) {
            temp = temp->Prev;
            counter2--;
        }
        while (temp != nullptr) {
            if (counter2 == receiver + 1) {
                msg->ReceiverS = temp->Prev;
                sleep(temp->send_speed); //для встановлення скільки часу повідомлення йде до сусіднього сервера
                sleep(msg->size * 1);
                temp = temp->Prev;
                counter2--;
            } else if (counter2 == receiver) {
                msg->ptod_nR = temp->Get_pr_numb();
                break;
            } else {
                if (temp->Get_pr_numb() == 1) { //1 тип програми
                    temp->used = temp->used + 1;
                    break;
                } else if (temp->Get_pr_numb() == 2) { //2 тип програми

                    sleep(temp->send_speed);
                    sleep(msg->size * 1);
                    counter2--;
                    temp = temp->Prev;
                    temp->used = temp->used + 1;
                } else if (temp->Get_pr_numb() == 3) { //3 тип програми
                    sleep(temp->send_speed);
                    sleep(msg->size * 1);
                    sleep(3);
                    temp = temp->Prev;
                    counter2--;
                    temp->used = temp->used + 1;
                } else if (temp->Get_pr_numb() == 4) { //4 тип програми
                    sleep(temp->send_speed);
                    sleep(msg->size * 1);
                    srand(time(0));
                    sleep(1 + rand() % 10);
                    temp = temp->Prev;
                    counter2--;
                    temp->used = temp->used + 1;
                } else if (temp->Get_pr_numb() == 5) { //5 тип програми
                    if (msg->type == "apk" || msg->type == "doc") {
                        sleep(temp->send_speed);
                        sleep(msg->size * 1);
                        temp = temp->Prev;
                        counter2--;
                        temp->used = temp->used + 1;
                    } else {
                        temp->used = temp->used + 1;
                        sleep(temp->send_speed);
                        sleep(msg->size * 1);
                        break;
                    }
                }
            }
        }
    }
}

//створює список серверів через які найчастіше проходили повідомлення
void Network_of_servers::make_list() {
    Server *current = this->first;
    List *lst = new List;
    while(current != 0)
    {
        lst->push_back(current->used, current->number);
        current = current->Next;
    }

    lst->sort();
    lst->Show();
}


int main() {
    Network_of_servers Network;

    Network.add_server(2, 1);
    Network.add_server(3, 1);
    Network.add_server(2, 1);
    Network.add_server(3, 1);
    Network.add_server(3, 1);
    Network.add_server(2, 1);
    Network.add_server(3, 1);
    Network.add_server(5, 1);
    Network.add_server(1, 1);
    Network.add_server(2, 2);


    Network.send_message(1, "apk", 2, 4);
    Network.send_message(1, "doc", 1, 6);
    Network.send_message(2, "ppt", 5, 8);
    Network.send_message(1, "xls", 1, 4);
    Network.send_message(2, "iso", 3, 9);

    Network.make_list();
    return 0;
}