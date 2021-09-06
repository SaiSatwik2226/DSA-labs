// 3. Define a Rectangle class that provides getLength amd getWidth. Write
// a program that creates an array of Rectangle and finds the largest Rectangle
// based on area.

#include<iostream> 
#include<conio.h> 

using namespace std;

class rec 
{ 
    private: 
        int i; 
        int b; 
    public: 
        rec(int a,int c) // Do nothing Parameterised Constructor
            { 
                i=a; 
                b=c; 
            } 
        void put() 
            { 
                cout<<"Area is : "<<i*b <<endl; 
            } 
};

int main() 
    { 
        //clrscr(); 
        rec obj[3]={rec(3,6),rec(2,5),rec(5,5)}; 
        cout<<"Displaying Areas of Rectangles : \n"; 
        for(int i=0;i<3;i++) 
            obj[i].put(); 
            getch();
        return 0; 
    } 
