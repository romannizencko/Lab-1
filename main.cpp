#include <iostream>
#include "Window.h"
#include <string>
#include <stdlib.h>

using namespace std;

void menu()
{
    cout << "\t\t\t***Menu***" << endl;
    cout << "\t0)Return to selection window" << endl;
    cout << "\t1)Print information about window" << endl;
    cout << "\t2)Set window's owner" << endl;
    cout << "\t3)Set window's title" << endl;
    cout << "\t4)Set window's color" << endl;
    cout << "\t5)Get owner" << endl;
    cout << "\t6)Get title" << endl;
    cout << "\t7)Get color" << endl;
    cout << "\t8)Copy window" << endl;
    cout << "\t9)Delete this window" << endl;
}

void showAllWindows(short countOfWindow, Window *Windows)
{
    for (short i = 0; i < countOfWindow; i++)
    {
        cout << i+1 << ")";
        Windows[i].print();
    }
}

int main()
{
    string tmpOwner, tmpTitle, tmpColor;
    short var = 0, countOfWindow = 1, i = 0, y = 0;
    Window *Windows = new Window[countOfWindow], *tmpWindows;
    while (1)
    {
        cout << "\nSelect window(up to" << countOfWindow << ") or close program(input 0)\n" << endl;
        showAllWindows(countOfWindow, Windows);
        cin >> i;
        if (i == 0)
        {
            delete Windows;
            return 0;
        }

        while (i != 0)
        {
            menu();
            cin >> var;
            switch (var)
            {
                case 0:
                    i = 0;
                    break;
                case 1:
                    Windows[i-1].print();
                    break;
                case 2:
                    cout << "\nEntry owner:" << endl;
                    cin >> tmpOwner;
                    Windows[i-1].setOwner(tmpOwner);
                    break;
                case 3:
                    cout << "\nEntry title:" << endl;
                    cin >> tmpTitle;
                    Windows[i-1].setTitle(tmpTitle);
                    break;
                case 4:
                    cout << "\nEntry color:" << endl;
                    cin >> tmpColor;
                    Windows[i-1].setColor(tmpColor);
                    break;
                case 5:
                    cout << "\nOwner:\t" << (tmpOwner = Windows[i-1].getOwner()) << endl;
                    break;
                case 6:
                    cout << "\nTitle:\t" << (tmpTitle = Windows[i-1].getTitle()) << endl;
                    break;
                case 7:
                    cout << "\nColor:\t" << (tmpColor = Windows[i-1].getColor()) << endl;
                    break;
                case 8:{
                    countOfWindow++;
                    tmpWindows = new Window[countOfWindow];
                    for (y = 0; y < countOfWindow-1; y++)
                    {
                        tmpWindows[y] = Windows[y];
                        delete &(Windows[y]);
                    }
                    delete Windows;
                    Windows = tmpWindows;
                    Window newWindow(Windows[i-1]);
                    Windows[countOfWindow-1] = newWindow;
                    break;}
                case 9:{
                    Windows[i-1] = Windows[countOfWindow-1];
                    delete &(Windows[countOfWindow-1]);
                    countOfWindow --;
                    tmpWindows = new Window[countOfWindow];
                    for (y = 0; y < countOfWindow; y++)
                    {
                        tmpWindows[y] = Windows[y];
                        delete &(Windows[y]);
                    }
                    delete Windows;
                    Windows = tmpWindows;
                    i = 0;
                    break;
                    }
            }
        }
    }
}
