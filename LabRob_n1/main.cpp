/**
 main.cpp
 Purpose: Shows how Lists, made in different ways are working, and how they
          are working in connection with other classes

 @author inmistlosted
 @version 1.0 20/11/18
 */

#include <string>
#include "List/List.h"
#include "CycleList/CycleList.h"
#include "ArrList/ArrList.h"
#include "Figures/Triangle/Types of Triangle/Types_of_Tri.h"
#include "Figures/Quadrilateral/Types of Quadrilateral/Type_of_Quad.h"
#include "Figures/Quadrilateral/Squares of Quadrilateral/Quad_Sq.h"
#include "Figures/Pentagon/Type_of_Pent/Type_of_Pent.h"
#include "Figures/Line/Line.h"

int main() {

    int l, i, index, find;
    char value;
    string word;
    cout << "What List do you want to make: List(1), Cycle List(2), Array List(3) or Library List(4)? ";
    cin >> l;
    cout << endl;

    if(l == 1)
    {
        List<char> list;
        list.push_back('p');
        list.push_back('r');
        list.push_back('o');
        list.push_back('g');
        list.push_back('r');
        list.push_back('a');
        list.push_back('m');

        list.Show();
        cout << endl << "Size of List: " << list.GetSize() << endl;
        cout << "Enter index of an element, which you want to find: ";
        cin >> index;
        cout << "Element with index " << index << " is " << list[index] << endl;
        cout << "Enter value of an element, which you want to find: ";
        cin >> value;
        cout << "Element with value " << value << " has index " << list.find(value) << endl;
        list.find_a();
    }
    else if(l == 2)
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
    else if(l == 3)
    {
        ArrList<int> arr;
        arr.push_back(12);
        arr.push_back(23);
        arr.push_back(54);
        arr.push_back(98);
        arr.push_back(43);
        arr.push_back(69);
        arr.push_back(666);

        arr.Show();
        cout << endl << "Size of List: " << arr.get_size() << endl;
        cout << "Enter index of an element, which you want to find: ";
        cin >> index;
        cout << "Element with index " << index << " is " << arr.find(index) << endl;
        cout << "Enter value of an element, which you want to find: ";
        cin >> find;
        cout << "Element with value " << find << " has index " << arr.find_index(find) << endl;
        arr.find_aliquot_3();
    }
    else if(l == 4)
    {
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
                    list<Triangle> list_of_triangles;
                    list_of_triangles.push_back(abc);

                    Type_of_Tri abc1(ab, bc, ac);
                    cout << "Length: \nAB = " << ab.length() << "\nBC = " << bc.length() << "\nAC = " << ac.length() << endl;
                    cout << "Perimetr ABC = " << abc.Perimetr() << endl;
                    cout << "Square ABC = " << abc.Square() << endl;
                    if(!abc1.IsRect())
                    {
                        abc1.Show_Rect();
                    }
                    abc1.IsIsos();

                    if(!list_of_triangles.empty())
                    {
                        cout << "Your Triangle was added to the List of Triangles!!!!!!!!!!!!!" << endl;
                    }
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

                    list<Quadrilateral> list_of_Quad;
                    list_of_Quad.push_back(abcd);

                    Type_of_Quad abcd2(ab, bc, cd, ad, ac);
                    cout << "Length: \nAB = " << ab.length() << "\nBC = " << bc.length() << "\nCD = " << cd.length() << "\nAD = " << ad.length() << endl;
                    abcd2.IsParallelogram();
                    abcd2.IsRhombus();
                    abcd2.IsTrapeze();
                    cout << "Perimetr ABCD = " << abcd.Perimetr() << endl;

                    if(!list_of_Quad.empty())
                    {
                        cout << "Your Quadrilateral was added to the List of Quadrilaterals!!!!!!!!!!!!!" << endl;
                    }
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

                    list<Pentagon> list_of_Pentagons;
                    list_of_Pentagons.push_back(abcde);

                    Type_of_Pent abcde2(ab, bc, cd, de, ae);
                    cout << "Length: \nAB = " << ab.length() << "\nBC = " << bc.length() << "\nCD = " << cd.length() << "\nDE = " << de.length() <<"\nAE = " << ae.length() << endl;
                    abcde2.IsRightPent();
                    cout << "Perimetr ABCDE = " << abcde.Perimetr() << endl;

                    if(!list_of_Pentagons.empty())
                    {
                        cout << "Your Pentagon was added to the List of Pentagons!!!!!!!!!!!!!" << endl;
                    }
                }
            }
        }
        else
        {
            cout << "There is no figure under number " << i << endl;
        }
    }
    return 0;
}