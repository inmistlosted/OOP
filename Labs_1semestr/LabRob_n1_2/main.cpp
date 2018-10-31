#include <iostream>
#include <cmath>

using namespace std;

class Point         //клас точки
{
public:
    double x;  
    double y;
};

class Distance  //клас відрізка
{
public:
    Point a;
    Point b;
    double length() // довжина відрізка
    {
        double ln = sqrt(((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)));
        return ln;
    }
    double length_2() // довжина відрізка у квадраті
    {
        double ln_2 =((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y));
        return ln_2;
    }

    bool NotSimiliar() //перевірка щоб кінці відрізка не були однією точкою
    {
        if(a.x == b.x && a.y == b.y)
        {
            cout << "Points (" << a.x << ", " << a.y << ") and (" << b.x << ", " << b.y << ") are similiar!" << endl;
            return 0;
        }
        else
        {
            return 1;
        }
    }
};

class Line // клас лінія, щоб перевірити чи точки не лежать на одній лінії
{
public:
    Point a;
    Point b;
    Point c;

    Line(Point a, Point b, Point c) //конструктор
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    bool OneLine() // перевірка чи точки не лежать на одній лінії
    {
        double k = (a.y - b.y) / (a.x - b.x);
        double l = b.y - k * b.x;
        if(c.y == k * c.x + l)
        {
            cout << "Points (" << a.x << ", " << a.y << "), ("<< b.x << ", " << b.y << "), (" << c.x << ", " << c.y << ") are on the same line!" << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

class Triangle // клас трикутників
{
public:

    Distance d1;
    Distance d2;
    Distance d3;

    Triangle(Distance d1, Distance d2, Distance d3) //конструктор
    {
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
    }

    bool IsTriangle() //перевірка чи є трикутником фігура
    {
        double d1_d2 = d1.length() + d2.length();
        double d2_d3 = d2.length() + d3.length();
        double d1_d3 = d1.length() + d3.length();

        if(d1_d2 <= d3.length() || d2_d3 <= d1.length() || d1_d3 <= d2.length())
        {
            cout << "This is not triangle" << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    double Perimetr() //периметр
    {
        double p_tr = d1.length() + d2.length() + d3.length();
        return p_tr;
    }

    double Square() // площа
    {
        double half_p = Perimetr() / 2;
        double sqr = sqrt(half_p * (half_p - d1.length()) * (half_p - d2.length()) * (half_p - d3.length()));
        return sqr;
    }

};

class Type_of_Tri : public Triangle //клас типів трикутників
{
public:
    Type_of_Tri(Distance d1, Distance d2, Distance d3) : Triangle(d1,d2,d3) //конструктор
    {
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
    }

    bool IsRect() // перевірка чи є прямокутним трикутником
    {
        double d1_2 = d1.length_2();
        double d2_2 = d2.length_2();
        double d3_2 = d3.length_2();
        double ad1_d2 = d1_2 + d2_2;
        double ad1_d3 = d1_2 + d3_2;
        double ad2_d3 = d2_2 + d3_2;
        if(ad1_d2 == d3_2 || ad2_d3 == d1_2 || ad1_d3 == d2_2)
        {
            return 0;
        }
        else
        {
            return 1;
        }

    }

    void Show_Rect() // функція щоб вивести, що трикутник прямокутний
    {
        cout << "This triangle is Rectangular" << endl;
    }


    bool IsEqual() //  перевірка чи є рівностороннім трикутником
    {
        if(d1.length() == d2.length() && d1.length() == d3.length() && d2.length() == d3.length())
        {
            return 0;
        }
        else
        {
            return 1;
        }

    }

    bool IsIsos() // перевірка чи є рівнобедренним трикутником
    {
        if(d1.length() == d2.length() || d1.length() == d3.length() || d2.length() == d3.length())
        {
            if(!IsEqual())
            {
                cout << "This triangle is Equilateral" << endl;
                return 1;
            }
            else {
                cout << "This triangle is Isosceles" << endl;
                return 0;
            }
        }
        else
        {
            return 1;
        }

    }
};

class Quadrilateral //клас чотирикутників
{
public:
    Distance d1;
    Distance d2;
    Distance d3;
    Distance d4;
    Distance d1_d2;

    Quadrilateral(Distance d1, Distance d2, Distance d3, Distance d4, Distance d1_d2) //конструктор
    {
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
        this->d4 = d4;
        this->d1_d2 = d1_d2;
    }

    double Perimetr() // периметр
    {
        double p_qd = d1.length() + d2.length() + d3.length() + d4.length();
        return p_qd;
    }
};

class Quad_Sq : public Quadrilateral // клас площ чотирикутників
{
public:
    Quad_Sq(Distance d1, Distance d2, Distance d3, Distance d4, Distance d1_d2) : Quadrilateral(d1,d2,d3,d4,d1_d2) //конструктор
    {
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
        this->d4 = d4;
        this->d1_d2 = d1_d2;
    }

    double Square() //загальна площа
    {
        double half_p = Perimetr() / 2;
        double sqr = sqrt((half_p - d1.length()) * (half_p - d2.length()) * (half_p - d3.length()) * (half_p - d4.length()));
        return sqr;
    }

    double S_TRap1() //площа трапеції перший варіант(у випадку що основи 1-ша та 3-тя сторони)
    {
        double a = d2.length();
        double b = d4.length();
        double c = d1.length();
        double d = d3.length();
        double s = (a + b) / 2 * sqrt(pow(c,2) - pow((pow(a - b,2) + c * c - d * d)/ 2 / (a - b),2));
        return s;
    }

    double S_TRap2() //площа трапеції другий варіант(у випадку що основи 1-ша та 3-тя сторони)
    {
        double a = d2.length();
        double b = d4.length();
        double c = d1.length();
        double d = d3.length();
        double half_p = Perimetr() / 2;
        double s = (a+b)/(a-b) * sqrt((half_p - a) * (half_p - b) * (half_p - a - c) * (half_p - a - d));
        return s;
    }

    double S_TRap1_1()//площа трапеції перший варіант(у випадку що основи 2-га та 4-та сторони)
    {
        double a = d1.length();
        double b = d3.length();
        double c = d2.length();
        double d = d4.length();
        double s = (a + b) / 2 * sqrt(pow(c,2) - pow((pow(a - b,2) + c * c - d * d)/ 2 / (a - b),2));
        return s;
    }

    double S_TRap2_2()//площа трапеції другий варіант(у випадку що основи 2-га та 4-та сторони)
    {
        double a = d1.length();
        double b = d3.length();
        double c = d2.length();
        double d = d4.length();
        double half_p = Perimetr() / 2;
        double s = (a+b)/(a-b) * sqrt((half_p - a) * (half_p - b) * (half_p - a - c) * (half_p - a - d));
        return s;
    }

    double S_Sq() // площа квадрата
    {
        double s = d1.length() * d1.length();
        return s;
    }

    double S_Rect() // площа прямокутника
    {
        double s = d1.length() * d2.length();
        return s;
    }


};

class Type_of_Quad : public Quad_Sq // клас типів чотирикутників
{
public:
    Type_of_Quad(Distance d1, Distance d2, Distance d3, Distance d4, Distance d1_d2) : Quad_Sq(d1,d2,d3,d4,d1_d2)//конструктор
    {
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
        this->d4 = d4;
        this->d1_d2 = d1_d2;
    }

    bool IsSquare() //перевірка чи є квадратом
    {
        Type_of_Tri d1d2(d1,d2,d1_d2);
        if(d1.length() == d2.length() && d2.length() == d3.length() && d3.length() == d4.length() && d1d2.IsRect() == true)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    bool IsRhombus() //перевірка чи є ромбом
    {
        if(d1.length() == d2.length() && d2.length() == d3.length() && d3.length() == d4.length())
        {
            if(IsSquare() == true)
            {
                cout << "This Quadrilateral is Square" << endl;
                cout << "Square: " << S_Sq() << endl;
                return 1;
            }
            else
            {
                cout << "This Quadrilateral is Rhombus" << endl;
                cout << "Square: " << Square() << endl;
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }

    bool IsRectangle() //перевірка чи є прямокутником
    {
        Type_of_Tri d1d2(d1,d2,d1_d2);
        if(d1.length() == d3.length() && d2.length() == d4.length() && d1.length() != d2.length() && d1d2.IsRect() == true)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    bool IsParallelogram() //перевірка чи є паралелограмом
    {
        Type_of_Tri d1d2(d1,d2,d1_d2);
        if(d1.length() == d3.length() && d2.length() == d4.length() && d1.length() != d2.length())
        {
            if(IsRectangle())
            {
                cout << "This Quadrilateral is Rectangular" << endl;
                cout << "Square: " << S_Rect() << endl;
                return 1;
            }
            else
            {
                cout << "This Quadrilateral is Parallelogram" << endl;
                cout << "Square: " << Square() << endl;
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }

    bool IsTrapeze() //перевірка чи є трапецією
    {
        if(S_TRap1() == S_TRap2())
        {
            cout << "This is Trapeze" << endl;
            cout << "Square: " << S_TRap1() << endl;
            return 0;
        }
        else if(S_TRap1_1() == S_TRap2_2())
        {
            cout << "This is Trapeze" << endl;
            cout << "Square: " << S_TRap1() << endl;
            return 0;
        }
        else
        {
            return 1;
        }
    }
};

class Pentagon // клас п'ятикутників
{
public:
    Distance d1;
    Distance d2;
    Distance d3;
    Distance d4;
    Distance d5;

    Pentagon(Distance d1, Distance d2, Distance d3, Distance d4, Distance d5) // конструктор
    {
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
        this->d4 = d4;
        this->d5 = d5;
    }

    double Perimetr() // периметр
    {
        double p_qd = d1.length() + d2.length() + d3.length() + d4.length() + d5.length();
        return p_qd;
    }

    double Sq_Rt() //площа правильного п'ятикутника
    {
        double s = d1.length_2() * sqrt(25 + 10 * sqrt(5)) / 4;
        return s;
    }

    double Sq() //площа будь-якого п'ятикутника
    {
        double a = d1.length() / 2 / tan(180 / 5);
        double s = Perimetr() * a / 2;
        return s;
    }
};

class Type_of_Pent : public Pentagon //клас тивів п'ятикутників
{
public:
    Type_of_Pent(Distance d1, Distance d2, Distance d3, Distance d4, Distance d5) : Pentagon(d1,d2,d3,d4,d5) // конструктор
    {
        this->d1 = d1;
        this->d2 = d2;
        this->d3 = d3;
        this->d4 = d4;
        this->d5 = d5;
    }

    bool IsRightPent() // перевірка чи є п'ятикутник правильним
    {
        if(d1.length() == d2.length() && d2.length() == d3.length() && d3.length() == d4.length() && d4.length() == d5.length())
        {
            cout << "This is the Right Pentagon" << endl;
            cout << "Square ABCDE = " << Sq_Rt() << endl;
            return 0;
        }
        else
        {
            cout << "Square ABCDE = " << Sq() << endl;
            return 1;
        }
    }
};


int main() {
    int i;

    cout << "What geometric figure do you want to make?\nEnter:\n 1 - Triangle\n 2 - Quadrilateral\n 3 - Pentagon" << endl;
    cin >> i;
    cout << endl;

    if(i == 1)
    {
        Point a;
        Point b;
        Point c;
        cout << "Enter please coordinates of point A: ";
        cin >> a.x >> a.y;
        cout << "Enter please coordinates of point B: ";
        cin >> b.x >> b.y;
        cout << "Enter please coordinates of point C: ";
        cin >> c.x >> c.y;
        cout << endl;

        Line l(a,b,c);
        l.OneLine();
        Distance ab;
        ab.a = a;
        ab.b = b;
        Distance ac;
        ac.a = a;
        ac.b = c;
        Distance bc;
        bc.a = b;
        bc.b = c;

        if(ab.NotSimiliar() && bc.NotSimiliar() && ac.NotSimiliar())
        {
            Triangle abc(ab,bc,ac);
            if(!abc.IsTriangle()) {
                Type_of_Tri abc1(ab, bc, ac);
                cout << "Length: \nAB = " << ab.length() << "\nBC = " << bc.length() << "\nAC = " << ac.length() << endl;
                cout << "Perimetr ABC = " << abc.Perimetr() << endl;
                cout << "Square ABC = " << abc.Square() << endl;
                if(!abc1.IsRect())
                {
                    abc1.Show_Rect();
                }
                abc1.IsIsos();
            }
        }
    }
    else if(i == 2)
    {
        Point a;
        Point b;
        Point c;
        Point d;
        cout << "Enter please coordinates of point A: ";
        cin >> a.x >> a.y;
        cout << "Enter please coordinates of point B: ";
        cin >> b.x >> b.y;
        cout << "Enter please coordinates of point C: ";
        cin >> c.x >> c.y;
        cout << "Enter please coordinates of point D: ";
        cin >> d.x >> d.y;
        cout << endl;
        Line abc(a,b,c);
        Line bcd(b,c,d);
        Line acd(a,c,d);
        Line abd(a,b,d);

        Distance ab;
        ab.a = a;
        ab.b = b;
        Distance bc;
        bc.a = b;
        bc.b = c;
        Distance cd;
        cd.a = c;
        cd.b = d;
        Distance ad;
        ad.a = a;
        ad.b = d;
        Distance ac;
        ac.a = a;
        ac.b = c;

        if(ab.NotSimiliar() && bc.NotSimiliar() && cd.NotSimiliar() && ad.NotSimiliar())
        {
            if(!abc.OneLine() && !bcd.OneLine() && !abd.OneLine() && !acd.OneLine())
            {
                Quadrilateral abcd(ab,bc,cd,ad,ac);
                Type_of_Quad abcd2(ab, bc, cd, ad, ac);
                cout << "Length: \nAB = " << ab.length() << "\nBC = " << bc.length() << "\nCD = " << cd.length() << "\nAD = " << ad.length() << endl;
                abcd2.IsParallelogram();
                abcd2.IsRhombus();
                abcd2.IsTrapeze();
                cout << "Perimetr ABCD = " << abcd.Perimetr() << endl;
            }
        }
    }else if(i == 3)
    {
        Point a;
        Point b;
        Point c;
        Point d;
        Point e;
        cout << "Enter please coordinates of point A: ";
        cin >> a.x >> a.y;
        cout << "Enter please coordinates of point B: ";
        cin >> b.x >> b.y;
        cout << "Enter please coordinates of point C: ";
        cin >> c.x >> c.y;
        cout << "Enter please coordinates of point D: ";
        cin >> d.x >> d.y;
        cout << "Enter please coordinates of point E: ";
        cin >> e.x >> e.y;
        cout << endl;
        Line abc(a,b,c);
        Line bcd(b,c,d);
        Line acd(a,c,d);
        Line abd(a,b,d);
        Line abe(a,b,e);
        Line ace(a,c,e);
        Line ade(a,d,e);
        Line bce(b,c,e);
        Line bde(b,d,e);
        Line cde(c,d,e);

        Distance ab;
        ab.a = a;
        ab.b = b;
        Distance bc;
        bc.a = b;
        bc.b = c;
        Distance cd;
        cd.a = c;
        cd.b = d;
        Distance de;
        de.a = d;
        de.b = e;
        Distance ae;
        ae.a = a;
        ae.b = e;

        if(ab.NotSimiliar() && bc.NotSimiliar() && cd.NotSimiliar() && de.NotSimiliar() && ae.NotSimiliar())
        {
            if(!abc.OneLine() && !bcd.OneLine() && !abd.OneLine() && !acd.OneLine() && !abe.OneLine() && !ace.OneLine() && !ade.OneLine() && !bce.OneLine() && !bde.OneLine() && !cde.OneLine())
            {
                Pentagon abcde(ab,bc,cd,de,ae);
                Type_of_Pent abcde2(ab, bc, cd, de, ae);
                cout << "Length: \nAB = " << ab.length() << "\nBC = " << bc.length() << "\nCD = " << cd.length() << "\nDE = " << de.length() <<"\nAE = " << ae.length() << endl;
                abcde2.IsRightPent();
                cout << "Perimetr ABCDE = " << abcde.Perimetr() << endl;
            }
        }
    }
    else
    {
        cout << "There is no figure under number " << i << endl;
    }
    return 0;
}