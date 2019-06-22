/**
  Figure.cpp
  Purpose: Defines class of Figure
 */

#include "Figure.h"

//shows the list of geometric figures
void showlist(list<Figure> figures)
{
    cout << "List of " << figures.size() << " geometric figures: " << endl << endl;
    while(!figures.empty())
    {
        cout << figures.front().type_of_figure << endl;
        cout << "Number of angles of this figure: " << figures.front().number_of_angles << endl;
        cout << "It's Square = " << figures.front().S << endl;
        cout << "It's Perimetr = " << figures.front().P << endl;
        cout << endl << endl;
        figures.pop_front();
    }
}