/* Program 4
Design an abstract class called Shape with two pure virtual functions getArea() and
getPerimeter() that return int values. Create a derived class Rectangle of Shape, with data
members length and breadth, with a suitable constructor and implementations for these virtual
functions. Likewise, create a derived class Circle of Shape with data member being radius, a
suitable constructor and implementations of the aforementioned virtual functions. Write also a
derived class Square of Rectangle, along the lines of Program 1. Demonstrate use of these
classes in the main() function. */

#include<iostream>
using namespace std;

class Shape{
    public:
    virtual float getArea()=0;
    virtual float getPerimeter()=0;
};

class Rectangle: public Shape{
    float l,b;
    public:
    //constructor
    Rectangle(float x,float y){
        l=x;
        b=y;
    }

    float getArea() override{
        return l*b;
    }

    float getPerimeter() override{
        return 2*(l+b);
    }
};

class Circle: public Shape{
    float r;
    public:
    //constructor
    Circle(float x){
        r=x;
    }

    float getArea() override{
        return 3.14*r*r;
    }

    float getPerimeter() override{
        return 2*3.14*r;
    }
};

class Square: public Rectangle
{
    public:
    Square (float s): Rectangle(s,s){}
};

int main (void)
{
    Rectangle rect (4, 5);
    Square squ (6);
    Circle c(7);

    // Print the area of the object.
    cout << "Rectangle area: " << rect.getArea () << endl;
    cout << "Rectangle Perimeter: " << rect.getPerimeter () << endl;
    // Print the area of the object.
    cout << "Square area: " << squ.getArea () << endl;
    cout << "Square Perimeter: " << squ.getPerimeter () << endl;
    // Print area and perimeter of Circle object
    cout << "Circle area: " << c.getArea () << endl;
    cout << "Circle Perimeter: " << c.getPerimeter () << endl;
    return 0;
}