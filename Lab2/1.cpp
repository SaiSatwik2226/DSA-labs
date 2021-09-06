/* Program 1
Write a C++ Program to create a class called Rectangle with data being its length and breadth;
write a constructor to initialize these values and a method getArea() that will return its area. Use
inheritance to create a derived class Square, whose constructor takes in a single parameter called
size, but reuses data and methods from Rectangle, including the getArea() method. */

#include<iostream>
using namespace std;

class Rectangle
{
    int length;
    int breadth;
    public:
        Rectangle (int l, int b)
        {
            length = l;
            breadth = b;
        }
        int getArea ()
        {
            //Compute and return area of rectangle
            return length*breadth;
        }
};
class Square:public Rectangle
{
    public:
    Square (int s):Rectangle(s,s){}
};

int main ()
{
    int l = 4, b = 5;
    Rectangle rt (l, b);
    int s = 10;
    Square sq (s);
    cout << "Rectangle Area:" << rt.getArea () << endl;
    cout << "Square Area : " << sq.getArea () << endl;
    return 0;
}