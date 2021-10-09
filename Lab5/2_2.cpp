// 2. Write a C++ program for circular linked lists for the following
// operations:

// ii. find the index of the position at the beginning who survives for the
// given inputs (n, k, s).
// Where n is the number of people standing in a circle,
// k is the parameter( k <= number of elements in the list),
// s is the starting position
// game logic: starting from 's' , remove every ‘k’th element in the circle
// linked list (clockwise) until one element is remaining. Once an element
// is out, the game restarts from the next position with the same ‘k’
// value.

#include <bits/stdc++.h>
using namespace std;
int element=0;

void helper_function(vector<int> List_of_people, int k, int s)
{
    int size = List_of_people.size();
    int removal;
    cout<<"steps of removal"<<endl;
    while (size>1)
    {
        removal = (s+k)%size;
        // cout<<List_of_people[removal]<<" ";
        s++;
        List_of_people.erase(List_of_people.begin()+removal);
        size = List_of_people.size();
        for (auto i = List_of_people.begin(); i != List_of_people.end(); i++)
        {
            cout<<*i<<" ";
        }
        cout<<endl;
    }
    cout<<"Final Element Remaining: "<<List_of_people.front();
    return;
}
int main()
{
    int n,k,s=0;
    cout<<"Enter the number of people sitting in round table"<<endl;
    cin>>n;
    cout<<"Enter the value of k"<<endl;
    cin>>k;
    cout<<"Enter the value of s"<<endl;
    cin>>s;
    k--;
    vector<int> List_of_people;
    for (int i = 1; i <= n; i++) {
        List_of_people.push_back(i);
    }
    helper_function(List_of_people, k, s);
    // cout<<element<<endl;
}