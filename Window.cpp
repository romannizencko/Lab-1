#include <iostream>
#include "Window.h"
#include <string>
#include <cstring>

using namespace std;
    Window :: Window()
    {}
    Window :: Window(string owner, string title, string color)
    {
        this -> owner = owner;
        this -> title = title;
        this -> color = color;
    }

    Window :: Window(const Window &window)
    {
        this -> owner = window.owner;
        this -> title = window.title;
        this -> color = window.color;
    }
    void Window :: print()
    {   cout << "Owner: " << owner << "\tTitle: \t" << title << "\tColor: " << color << endl;    }

    void Window :: setOwner(string owner)
    {   this -> owner = owner;  }

    void Window :: setTitle(string title)
    {   this -> title = title;  }

    void Window :: setColor(string color)
    {   this -> color = color;  }

    string Window :: getOwner()
    {
        return owner;
    }
    string Window :: getTitle()
    {
        return title;
    }

    string Window :: getColor()
    {
        return color;
    }
