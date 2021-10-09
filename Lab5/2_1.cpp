// 2. Write a C++ program for circular linked lists for the following

// i. check if a given linked list is circular or not.

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

bool isCircular(struct Node *head)
{
    Node* node=head;
    while(node!=NULL)
    {
        if(node->next==NULL) return false;
        if(node->next==head) return true;
        node=node->next;
    }
    return false;
}

int main()
{
    int i,n,l,k;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    cout<<"Enter 1 for circular and 0 for linear LL"<<endl;
    cin>>k;
    Node *head=NULL, *tail = NULL;
    int x;
    cin >> x;
    head = new Node(x);
    tail = head;
    for(int i=0;i<n-1;i++)
    {
        cin>>x;
        tail -> next = new Node(x);
        tail = tail -> next;
    }
    if (k==1 && n >= 1)
        tail->next = head;
    int des= isCircular(head);
    if(des==1) cout<<"Linked list is circular"<<endl;
    else cout<<"Linked list is not circular"<<endl;
    return 0;
}
