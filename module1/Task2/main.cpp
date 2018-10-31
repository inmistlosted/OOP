#include <iostream>
#include <cmath>  //fmod, pow
#include <string>
#include <utility>//pair
#include <vector>

using namespace std;

double logbase(double a, double base) //логарифм з заданою основою
{
    return log(a) / log(base);
}

template<typename T>
pair<string, double> f(T x) //f для всіх інших значень
{
    double result = 9583;
    string color = "red";
    return make_pair(color, result); //f повертая пару(колір, ціле значення)
}

template<>
pair<string, double> f<int>(int n) //f для цілих чисел
{
    if (n >= 0)//для натуральних(цілих додатніх) чисел
    {
        double result = fmod((pow(2, n) + n * n), 133);
        string color = "red";
        return  make_pair(color, result); //f повертая пару(колір, ціле значення)

    }
    else //для цілих від'ємних чисел
    {
        double result = fmod((pow(n, 5) + n - 1), 233);
        string color = "green";
        return make_pair(color, result); //f повертая пару(колір, ціле значення)
    }
}

template<>
pair<string, double> f<double>(double d) //f для дійсних чисел
{
    int a = 1 / sin(logbase(d, 2));
    int result = fmod(a, 333);
    string color = "blue";
    return make_pair(color, result); //f повертая пару(колір, ціле значення)
}

template<>
pair<string, double> f<string>(string s)//f для текстових рядків
{ //f рахує кількість слів довжину від 3 до 5 символів
    int word = 0;
    int count = 0;
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] != ' ')
        {
            word++;
            i++;
            if(s[i+1] == '\0')
            {
                if(word >= 3 && word <= 5)
                {
                    count++;
                }
            }
        }

        else
        {
            if(word >= 3 && word <= 5)
            {
                count++;
            }
            i++;
            word = 0;
        }
    }
    string color = "green";
    return make_pair(color, count); //f повертая пару(колір, ціле значення)
}

template<typename T,typename T1>
pair<string, double> f(pair<T, T1> ab)//f для пари чисел а і b
{
    string result_color;
    double f_a = f(ab.first).second;
    double f_b = f(ab.second).second;
    string a_color = f(ab.first).first;
    string b_color = f(ab.second).first;
    double result = fmod(pow(f_a, f_b),533);
    if(a_color == b_color)
    {
        result_color = a_color;
    }
    else
    {
        result_color = "yellow";
    }
    return make_pair(result_color, result); //f повертая пару(колір, ціле значення)
}

template<typename T>
pair<string, double> f(vector<T> v)//f для списку v
{   //f рахує суму і-того члена помноженого на (n-i)-тий член,
    //а також визначає який колір зустрічається найчастіше
    string color1 = "red";
    string color2 = "green";
    string color3 = "blue";
    string result_color;
    int red = 0, green = 0, blue = 0;
    int k = v.size();
    double sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += f(v[i]).second * f(v[k]).second;
        k--;
        string curr_color = f(v[i]).first;
        if(curr_color == color1)
        {
            red++;
            if(red == green && red > blue)
            {
                result_color = color1;
            }
            else if(red == blue && red > green)
            {
                result_color = color1;
            }else if(red == green && red == blue)
            {
                result_color = color1;
            }
        }
        else if(curr_color == color2)
        {
            green++;
            if(green == red && green > blue)
            {
                result_color = color2;
            }
            else if(green == blue && green > red)
            {
                result_color = color2;
            }else if(red == green && red == blue)
            {
                result_color = color2;
            }
        }else if(curr_color == color3)
        {
            blue++;
            if(blue == green && blue > red)
            {
                result_color = color3;
            }
            else if(blue == red && blue > green)
            {
                result_color = color3;
            }else if(red == green && red == blue)
            {
                result_color = color3;
            }
        }

    }
    if(red != green || red != blue || green != blue) {
        if (red > green) {
            if (red > blue) {
                result_color = color1;
            } else {
                result_color = color3;
            }
        } else {
            if (green > blue) {
                result_color = color2;
            } else {
                result_color = color3;
            }

        }
    }
    double result = fmod(sum, 733);
    return make_pair(result_color, result); //f повертая пару(колір, ціле значення)
}

int main()
{
    f(10); //f(n)
    f(-10); //f(-n)

    cout << f(8.56).second; //f(d)

    f((string)"dgdf dfgdagh fgh gd wrwr gfg"); //f(s)

    pair<double, int> ab;
    ab.first = 8.14;
    ab.second = 27;
    f(ab); //f(a,b)

    vector<int> v{ -2,-1, 0 ,1,2,3,4 };
    f(v); //f(списку)

    f("f"); //f(char)

    return 0;
}