/* 2. Create a custom class for a doubly linked list with header and
trailer sentinels that stores integer values at its data and allows the
following operations:
• push(x): push a node with value x at the end of the list,
• insertNode(pos, x): insert a node at position pos with value x,
• deleteNode(pos): deletes the node at position pos,
• print(): prints the entire list
• goForward(x): Shift the first node with value x forward by one
place. So, if the list is 1<=>2<=>3<=>2<=>4 and x is 2, then the
new list should be 1<=>3<=>2<=>2<=>4
• goBackward(x): Similar to goForward(x), but in the backward
direction.
For goForward and goBackward, handle the appropriate edge cases
by throwing error. If there are multiple x, shift only the first x. Also
note to shift the node itself and not just the values. */

#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next, *prev;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    };
};
class DoublyLinkedList
{
private:
    struct Node *head, *tail;
public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void push(int x)
    {
        struct Node *newNode=new Node(x);
        if(head==NULL)
        {
            newNode->prev=NULL;
            newNode->next=NULL;
            head=newNode;
            tail=newNode;
            return;
        }
        newNode->prev = tail;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    void insertNode(int position, int x)
    {
        struct Node *newNode=new Node(x);
        if(!newNode)
        {
            throw runtime_error("Memory limit exceeded");
        }
        if(position==1)
        {
            newNode->prev=NULL;
            newNode->next=head;
            if(head)
                head->prev=newNode;
            head=newNode;
        }
        else
        {
            struct Node *temp=head;
            int k=1;
            while(k<(position-1) && (temp->next)!=NULL) //IMPORTANT!!!!
            {
                k++;
                temp=temp->next;
            }
            if(k!=(position-1)) //IMPORTANT!!!!
            {
                throw runtime_error("Desired position does not exist");
            }
            if(temp->next == NULL)
            {
                tail = newNode;
            }
            newNode->next=temp->next;
            newNode->prev=temp;
            if(newNode->next)
            newNode->next->prev=newNode;
            temp->next=newNode;
        }
    }
    void deleteNode(int position)
    {
        if(head==NULL)
        {
            throw runtime_error("List is empty");
        }
        if(position==1)
        {
            struct Node *temp=head;
            head=head->next;
            if(head->next)
                head->prev=NULL;
            delete(temp);
            return;
        }
        else
        {
            struct Node *temp=head;
            int k=1;
            while(k<(position) && temp!=NULL)
            {
                k++;
                temp=temp->next;
            }
            if(temp==NULL)
            {
                throw runtime_error("Desired position does not exist");
            }
            if(temp->next==NULL)
            {
                tail = temp->prev;
            }
            struct Node *temp2=temp->prev;
            temp2->next=temp->next;
            if(temp->next)
                temp->next->prev=temp2;
            free(temp);
        }
    }
    void goForward(int element)
    {
        //Write blocks of code here for forward operation.
        //For doing this you need to traverse the list to find if the element is present in the list and starting from that point    you go forward one node
        struct Node *forwardingNode=head;
        while(forwardingNode->data!=element && forwardingNode->next!=NULL){
            forwardingNode = forwardingNode->next;
        }
        if(forwardingNode->data==element && forwardingNode->next==NULL){
            printf("Operation Not Possible");
        }
        if(forwardingNode->next==NULL){
            printf("No such Element\n");
        }
        else if (forwardingNode->data==element)
        {       
            int temp;
            temp = forwardingNode->next->data;
            forwardingNode->next->data = forwardingNode->data;
            forwardingNode->data = temp;
        }
    }
    void goBackward(int element)
    {
        //write blocks of code here for backward operation.
        //same as the forward operation but here you will have to write code for backward operation.
        struct Node *forwardingNode=head;
        while(forwardingNode->data!=element && forwardingNode->next!=NULL){
            forwardingNode = forwardingNode->next;
        }
        if(forwardingNode->data==element && forwardingNode->prev==NULL){
            printf("Operation Not Possible");
        }
        if(forwardingNode->next==NULL){
            printf("No such Element\n");
        }
        else if (forwardingNode->data==element)
        {       
            int temp;
            temp = forwardingNode->next->data;
            forwardingNode->next->data = forwardingNode->data;
            forwardingNode->data = temp;
        }
    }
    void print()
    {
        struct Node *p=head;
        while(p)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<"\n";
    }
};
int main()
{
    DoublyLinkedList myList;
    for(int i=0;i<10;i++){
        myList.push(i+1);
    }
    myList.print();
    // cout<<"Inserting 11 at pos 99\n";
    // myList.insertNode(99,11);
    // myList.print();
    // cout<<"Insering 99 at pos 12\n";
    // myList.insertNode(12,99);
    // myList.print();
    cout<<"Insering 56 at start\n";
    myList.insertNode(1,56);
    myList.print();
    cout<<"Deleting last element\n";
    myList.deleteNode(11);
    myList.print();
    cout<<"Deleting first element\n";
    myList.deleteNode(1);
    myList.print();
    cout<<"Deleting position 4\n";
    myList.deleteNode(4);
    myList.print();
}