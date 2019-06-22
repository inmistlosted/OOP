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
        list<Figure> figures;


        Point a;
        Point b;
        Point c;
        a.x = 0;
        a.y = 0;
        b.x = 2;
        b.y = 0;
        c.x = 0;
        c.y = 2;

        Line l(a, b, c);
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

        if (ab.NotSimiliar() && bc.NotSimiliar() && ac.NotSimiliar()) {
            Triangle abc(ab, bc, ac);
            if (!abc.IsTriangle()) {
                abc.S = abc.Square();
                abc.P = abc.Perimetr();
                figures.push_back(abc);
            }
        }

        Point d;
        d.x = 2;
        d.y = 2;
        Line bcd(b, c, d);
        Line acd(a, c, d);
        Line abd(a, b, d);

        Distance cd;
        cd.a = c;
        cd.b = d;
        Distance ad;
        ad.a = a;
        ad.b = d;

        if (ab.NotSimiliar() && bc.NotSimiliar() && cd.NotSimiliar() && ad.NotSimiliar()) {
            if (!l.OneLine() && !bcd.OneLine() && !abd.OneLine() && !acd.OneLine()) {
                Quadrilateral abcd(ab, bc, cd, ad, ac);
                Type_of_Quad abcd2(ab, bc, cd, ad, ac);
                abcd.P = abcd.Perimetr();
                abcd.S = abcd2.S_Sq();
                figures.push_back(abcd);



            }
        }

        Point q;
        Point w;
        Point s;
        q.x = 3;
        q.y = 3;
        w.x = 12;
        w.y = 3;
        s.x = 5;
        s.y = 5;

        Line ln(q, w, s);
        ln.OneLine();
        Distance qw;
        qw.a = q;
        qw.b = w;
        Distance ws;
        ws.a = w;
        ws.b = s;
        Distance qs;
        qs.a = q;
        qs.b = s;

        if (qw.NotSimiliar() && ws.NotSimiliar() && qs.NotSimiliar()) {
            Triangle qws(qw, ws, qs);
            if (!qws.IsTriangle()) {
                qws.S = qws.Square();
                qws.P = qws.Perimetr();
                figures.push_back(qws);

            }
        }

        Point e;
        e.x = 1;
        e.y = 3;
        Line abe(a, b, e);
        Line ace(a, c, e);
        Line ade(a, d, e);
        Line bce(b, c, e);
        Line bde(b, d, e);
        Line cde(c, d, e);

        Distance de;
        de.a = d;
        de.b = e;
        Distance ae;
        ae.a = a;
        ae.b = e;

        if (ab.NotSimiliar() && bc.NotSimiliar() && cd.NotSimiliar() && de.NotSimiliar() && ae.NotSimiliar()) {
            if (!l.OneLine() && !bcd.OneLine() && !abd.OneLine() && !acd.OneLine() && !abe.OneLine() &&
                !ace.OneLine() && !ade.OneLine() && !bce.OneLine() && !bde.OneLine() && !cde.OneLine()) {
                Pentagon abcde(ab, bc, cd, de, ae);
                abcde.S = abcde.Sq();
                abcde.P = abcde.Perimetr();

                figures.push_back(abcde);

                Type_of_Pent abcde2(ab, bc, cd, de, ae);

            }
        }



        Point k;
        Point i;
        Point t;
        k.x = -2;
        k.y = 1;
        i.x = -2;
        i.y = 5;
        t.x = -10;
        t.y = 4;

        Line lnl(k, i, t);
        lnl.OneLine();
        Distance ki;
        ki.a = k;
        ki.b = i;
        Distance it;
        it.a = i;
        it.b = t;
        Distance kt;
        kt.a = k;
        kt.b = t;

        if (ki.NotSimiliar() && it.NotSimiliar() && kt.NotSimiliar()) {
            Triangle kit(ki, it, kt);
            if (!kit.IsTriangle()) {
                kit.S = kit.Square();
                kit.P = kit.Perimetr();
                figures.push_back(kit);

            }
        }

        showlist(figures);
    }
    return 0;
}