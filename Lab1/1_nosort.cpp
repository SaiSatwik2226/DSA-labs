// C++ program to find second largest
// element in an array
#include <bits/stdc++.h>

using namespace std;

/* Function to print the second largest elements */

void print2largest(int arr[], int arr_size)
    {
        int i, first, second;
        /* There should be atleast two elements */
        if (arr_size < 2)
        {
            printf("Invalid Input");
            return;
        }

        int largest = arr[0];
        int second_lar = arr[0];

        for (int i = 0; i < arr_size; i++)
        {
            if(arr[i]>largest){
                largest = arr[i];
            }
        }

        for (int i = 0; i < arr_size; i++)
        {
            if(arr[i]>second_lar && arr[i]<largest){
                second_lar = arr[i];
            }
        }
        
        cout<<second_lar;
        return;
}

/* Driver program to test above function */
int main()
    {
    int arr[] = { 12, 35, 1, 10, 34, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    print2largest(arr, n);
    return 0;
    }