/* Program 3:
Write a program that creates a Student template class to store marks of a student in two subjects,
such that where the data type of the marks is specified when the object is created. Create a
method that prints the sum of these two marks. Create object of this class for two students, so
that the subject marks for the first student are integer values whereas the subject marks for the
second student are float values. */

#include<iostream>
using namespace std;

template <class T>
class Student{
    T m1,m2;
    public:
        Student(T m,T n){
            m1=m;
            m2=n;
        }
        T getSum(){
            return (T)(m1+m2);
        }
};

int main(){
    Student<int> s1(10,12);
    Student<float> s2(10.3,12.2);
    cout<<"marks 1 (10,12):"<<s1.getSum()<<endl;
    cout<<"marks 2 (10.3,12.2):"<<s2.getSum()<<endl;
    return 0;    
}