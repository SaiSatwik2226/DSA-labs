/* Program 2
Write a C++ Program to Add, Subtract, Multiply and Divide Complex Numbers Using
Operator Overloading with exception handling with any one of the cases. */

#include<iostream>
using namespace std;

class Complex{
    int i,r;
    public:
    void read(){
        cout<<"\nenter the real part:";
        cin>>r;
        cout<<"\nenter the imaginary part:";
        cin>>i;
    }
    void display(){
        cout<<"Complex number is "<<r<<"+"<<i<<"i\n";
    }

    Complex operator +(Complex a1){
        Complex a;
        a.r = r+a1.r;
        a.i = i+a1.i;
        return a;
    }

    Complex operator -(Complex a2){
        Complex a;
        a.r = r-a2.r;
        a.i = i-a2.i;
        return a;
    }

    Complex operator *(Complex a1){
        Complex a;
        a.r = r*a1.r + i+a1.i;
        a.i = r*a1.i + i*a1.r;
        return a;
    }

    Complex operator /(Complex a1){
        Complex a;
        a.r = (r*a1.r + i+a1.i)/((a1.r*a1.r)+(a1.i*a1.i));
        a.i = (r*a1.i + i*a1.r)/((a1.r*a1.r)+(a1.i*a1.i));
        return a;
    }

    Complex addComplex(Complex c1,Complex c2)//adding two Complex numbers
    {
        Complex c;
        c.r=c1.r+c2.r;
        c.i=c1.i+c2.i;
        return c;
    }

    Complex addComplex(Complex c1,Complex c2,Complex c3)//adding three Complex numbers
    {
        Complex c;
        c.r=c1.r+c2.r+c3.r;
        c.i=c1.i+c2.i+c3.i;
        return c;
    }
};

int main()
{
    int ch;

    Complex a,b,c;
    do
    {
        cout<<"\n1.Addition\n2.Subtraction";
        cout<<"\n3.Mulitplication\n4.Division\n5.Exit\n";
        cout<<"\nEnter the choice :";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter The First Complex Number:";
                a.read();
                a.display();
                cout<<"\nEnter The Second Complex Number:";
                b.read();
                b.display();
                c=a+b;
                c.display();
                break;
            case 2:
                cout<<"\nEnter The First Complex Number:";
                a.read();
                a.display();
                cout<<"\nEnter The Second Complex Number:";
                b.read();
                b.display();
                c=a-b;
                c.display();
                break;
            case 3:
                cout<<"\nEnter The First Complex Number:";
                a.read();
                a.display();
                cout<<"\nEnter The Second Complex Number:";
                b.read();
                b.display();
                c=a*b;
                c.display();
                break;
            case 4:
                cout<<"\nEnter The First Complex Number:";
                a.read();
                a.display();
                cout<<"\nEnter The Second Complex Number:";
                b.read();
                b.display();
                c=a/b;
                c.display();
                break;
        }
    }while(ch!=5);
}