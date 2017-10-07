#pragma once
#include <iostream>

using namespace std;

class Rectangle
{
protected:
    int width, height;
public:
    virtual void display() const
    {
        cout << width << " " << height << endl;
    }
};

class RectangleArea : public Rectangle
{
public:
    void read_input()
    {
        cin >> width >> height;
    }

    void display()
    {
        cout << width * height << endl;
    }
};