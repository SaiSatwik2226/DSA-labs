//all string permutations

#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;

void permute(string &str, int low, int high)
    {
        // when last index is
        // reached print the string.
        if (low == high)
            cout << str << endl;
        else
        {
            for (int j = low; j < str.length(); j++)
                {
                    /*fill in the logic*/
                    // Swapping done
                    swap(str[low], str[j]);
        
                    // Recursion called
                    permute(str, low+1, high);
        
                    //backtrack
                    swap(str[low], str[j]);
                }
    }
}

void permute(string &str)
    {
        int n = str.length()-1;
        permute(str, 0, n);
    }

int main()
    {
        // Declare the variable str
        // of string data type.
        string str;
        // Prompt and read
        // the input from the user.
        cout << "Enter a string: ";

        cin >> str;
        // Prompt and call
        // the driver function.
        cout << "The permutations are: " << endl;
        // Call the function permute
        // with string str as a parameter.
        permute(str);
        return 0;
    }