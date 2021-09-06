/* Program 2:
Write a program to compute the product of two numbers each of different data types using a
Function Template. */

#include<iostream>
using namespace std;

template <typename T1, typename T2> T2 product (T1 x, T2 y){
    return (T2) (x*y);
}

int main(){
    cout<<"output (2,2.2):"<<product(2,2.2)<<endl;
    cout<<"output (2.2,2):"<<product(2.2,2)<<endl;
    return 0;
}