/* 3. Write a C++ program for the inserting the content of given file into
a linked list. Each node of the linked list has the following attributes:
a) str : a character array that stores the word. You may convert
the all the words to lowercase
b) count: an integer that stores the number of times str appears
in the document
c) next: a node pointer, pointing to the node corresponding to the
next word in the document
Input (passed as command line arguments) : name of the input file
which has to be read, and name of the output file into which the linked
list will be printed.
Sample Input: input.txt output.txt
Content of input.txt:
This is a file. The file contains the code. The code is written in C++
Sample Output: The content of output.txt should look like:
this 1
is 2
a 1
file 2
the 3
file 2
contains 1
the 3
code 2
the 3
code 2
is 2
written 1
in 1
c++ 1 */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;

struct Node
{
    char *str;
    int count;
    struct Node *next;
    Node(char* word, int freq)
    {
        str = (char*)malloc(strlen(word)+1);
        strcpy(str, word);
        count = freq;
        next = NULL;
    }
};
class WordList
{
    private:
    struct Node *head, *tail;
    int updateFrequencies(char* word)
    {
        /*this function should update the frequencies
        of all the nodes having the current word,
        and return the total number of times the word had
        appeared so far
        */
        int finalCount;
        Node *pointer=head;
        while(pointer->next!=NULL){
            if(pointer->str == word){
                pointer->count = pointer->count+1;
                finalCount = pointer->count;
            }
        }
        return finalCount;
    }
    public:
    WordList(){
    head = NULL;
    tail = NULL;
    }
    //the function returns 1 if the node was added successfully, else 0
    int pushWord(char* word)
    {
        int freq = updateFrequencies(word);
        struct Node* newNode = new Node(word, freq+1);
        if(newNode == NULL)
        {
            return 0;
        }
        //base case when the list is empty
        if(tail==NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        return 1;
    }
    void printToFile(char* filename)
    {
        FILE *myOutput = fopen (filename, "w+");
        if (myOutput == 0)
            printf ("output file not opened \n");
        struct Node* ptr = head;
        while (ptr != NULL)
        {
            fprintf (myOutput, "%s %d \n", ptr->str, ptr->count);
            ptr = ptr->next;
        }
    }
};
int main (int argc, char *argv[])
{
    WordList myList;
    char *delim = ". ,:;\t\n\0";
    FILE *myFile;
    FILE *myOutput;
    char *filename = argv[1];
    char *outputfile = argv[2];
    if (argc != 3)
    {
        fprintf (stderr, "error: insufficient input");
        return 1;
    }
    myFile = fopen (filename, "r+");
    if (myFile == 0)
    {
        printf ("input file not opened\n");
        return 1;
    }
    /*start reading file character by character when word has been detected; push the word to linked list */
    char ch = 0; int word = 1, k = 0;
    char thisword[100];
    while ((ch = fgetc(myFile)) != EOF)
    {
        if (strchr (delim, ch))
        {
            /* insert the code here to push the word into the list and handle appropriate edge cases */
            int status = myList.pushWord(thisword);
        }
        else
        { /* if not delim, add char to string, set word 1 */
            word = 1;
            thisword[k++] = tolower (ch);
        }
    }
    /* handle non-POSIX line-end */
    if (word == 1 && k>0)
    {
        thisword[k] = '\0';
        int status = myList.pushWord(thisword);
        if(status!=1)
        {
            fprintf (stderr, "error: adding the word failed.\n");
        }
    }
    myList.printToFile(outputfile);
    return 0;
}
