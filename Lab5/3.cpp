// 3. Write a C++ program for reversing a linked list without using extra space using recursion

// Recursive C++ program to reverse
// a linked list
#include <iostream>
using namespace std;
/* Link list node */
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
struct LinkedList {
    Node* head;
    LinkedList()
    {
        head = NULL;
    }
    Node* reverse(Node* head)
    {
        //Block of code;
        Node* cur = head;
        Node *next = NULL, *prev = NULL;
        if (cur == NULL)
        {
            return prev;
        }
        else
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            return reverse(cur);
        }
    }

    /* Function to print linked list */
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
    }

    }
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
    ll.push(111);
    cout << "Given linked list\n";
    ll.print();
    ll.head = ll.reverse(ll.head);
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}