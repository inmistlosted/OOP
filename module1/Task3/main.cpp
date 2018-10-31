#include <iostream>
#include <vector>

using namespace std;

double S = 0; //глобальна змінна S

class Base //клас Base
{
public:
    Base *base1_ptr = nullptr; //вказівник на перший вкладений екземпляр класу Base
    Base *base2_ptr = nullptr; //вказівник на другий вкладений екземпляр класу Base

    Base() //конструктор
    {
        this->N = counter;
        this->counter++;
    }

    virtual ~Base() //деструктор
    {
        S = 3 * S + this->N - 33;
    }

    void Set_base_pts(Base *base1, Base *base2)
    {
        this->base1_ptr = base1;
        this->base2_ptr = base2;
    }

    pair<Base*, Base*> Get_base_ptrs()
    {
        return make_pair(base1_ptr, base2_ptr);
    }

    virtual void Destruct_simulator(double &curr_S) //функція, яка симулює як поведе себе деструктор Base
    {
        curr_S = 3 * curr_S + this->N - 33;
    }

protected:
    int N; //порядковий номер
    static int counter;
};

int Base::counter = 0;

class Alpha : public Base //клас Alpha - підклас Base
{
public:
    virtual ~Alpha() //деструктор Alpha
    {
        S = S / 3 - this->N;
    }

    virtual void Destruct_simulator(double &curr_S) //функція, яка симулює як поведе себе деструктор Alpha
    {
        curr_S = curr_S / 3 - this->N;
        Base::Destruct_simulator(curr_S);
    }
};

class Beta : public Base //клас Beta - підклас Base
{
public:
    virtual ~Beta() //деструктор Beta
    {
        S = S + 2 * this->N + 33;
    }

    virtual void Destruct_simulator(double &curr_S) //функція, яка симулює як поведе себе деструктор Beta
    {
        curr_S = curr_S + 2 * this->N + 33;
        Base::Destruct_simulator(curr_S);
    }
};

class Red : public Alpha //клас Red - підклас Alpha
{
public:
    ~Red() override //деструктор Red
    {
        S = S - this->N / 2;
    }

    void Destruct_simulator(double &curr_S) override //функція, яка симулює як поведе себе деструктор Red
    {
        curr_S = curr_S - this->N / 2;
        Alpha::Destruct_simulator(curr_S);
    }
};

class Green : public Alpha //клас Green - підклас Alpha
{
public:
    ~Green() override //деструктор Green
    {
        S = S - this->N / 2 - 24;
    }

    void Destruct_simulator(double &curr_S) override //функція, яка симулює як поведе себе деструктор Green
    {
        curr_S = curr_S - this->N / 2 - 24;
        Alpha::Destruct_simulator(curr_S);
    }
};

double predict_S(vector<Base*> &objects) //функція, яка передбачає чому буде дорівнювати S
{
    double curr_S = S;
    for(int i = 0; i < objects.size(); i++)
    {
        objects[i]->Destruct_simulator(curr_S); //Для кожного об'єкту із списку симулюється деструктор
    }
    return curr_S;
}

template<typename T>
class smart_pointer //смарт поінтер
{
public:
    T *M_obj;

    smart_pointer(T *obj)
            : M_obj(obj)
    {}                      //дозволяє швидко видаляти об'єкти
    //класу, які були використані
    ~smart_pointer()
    {
        delete M_obj;
    }

    T*operator->() { return M_obj; }
    T&operator*() { return *M_obj; }
};


int main() {
    Alpha *a = new Alpha;
    Beta *b = new Beta;
    Red *r = new Red;
    Green *g = new Green;
    Base *base;
    vector<Base*> vctr;

    base = &(*a);
    vctr.push_back(base);
    base = &(*b);
    vctr.push_back(base);   //записуємо об'єкти класів в вектор(список)
    base = &(*g);
    vctr.push_back(base);
    base = &(*r);
    vctr.push_back(base);
    cout << "In the begining S = " << S << endl;
    cout << "Predicted value for S = " << predict_S(vctr) << endl;

    delete a;
    delete b;
    delete r;
    delete g;
    cout << "Actual value of S = " << S << endl;

//Реалізація без delete
    vctr.clear();
    {
        smart_pointer<Red> bs_ptr1(new Red);
        smart_pointer<Green> bs_ptr2(new Green); //передаємо класи в користування смарт поінтеру
        smart_pointer<Alpha> bs_ptr3(new Alpha);
        smart_pointer<Beta> bs_ptr4(new Beta);

        vctr.push_back((Base*)bs_ptr4.M_obj);
        vctr.push_back((Base*)bs_ptr3.M_obj); //записуємо об'єкти класів в вектор(список)
        vctr.push_back((Base*)bs_ptr2.M_obj);
        vctr.push_back((Base*)bs_ptr1.M_obj);

        cout << "\nnow S = " << S << endl;
        cout << "Predicted value for S after all objects are deleted = " << predict_S(vctr) << endl;

    }

    cout << "Actual value of S = " << S << endl;
    return 0;
}