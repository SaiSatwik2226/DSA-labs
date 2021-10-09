// a) Given a sorted array of integers, write a program to find an element in it and return its index. The algorithm should complete the task in O(log2n) time, where n is the number of elements in the array. Implement your algorithm through both iterative and recursive approach. Take care of the following edge cases:
// •	If the element does not exist, return the index of the next smallest number just greater than the element.
// •	If the element is greater than all the integers in the array, return the length of the array
// •	If multiple copies of the element occur, return the first occurrence

#include<iostream>
#include<stdio.h>

using namespace std;

int binarySearchIterative(int* arr, int len, int ele){
    int low = 0, high = len;
    int mid1,mid2;
    while (low<high)
    {
        mid1 = (low+high)/3;
        mid2 = 2*(low+high)/3;
        if (arr[mid1]>=ele)
        {
            high = mid1;
        }
        else if (arr[mid2]>=ele)
        {
            high = mid2;
        }

        if(arr[mid2]<ele){
            low = mid2+1;
        }
        else if(arr[mid1]<ele)
        {
            low = mid1+1;
        }              
        cout<<low<<" "<<high<<endl;
    }
    if(low<len && arr[low]<ele)
		return low+1;
	return low;
}

int binarySearchRecursive(int* arr, int len, int ele, int low, int high){
	//base case
	if(low>=high){
		if(low<len && arr[low]<ele){
			return low+1;
		}
		else {
			return low;
		}
	}
    int mid1 = (low+high)/3;
    int mid2 = 2*(low+high)/3;
	if (arr[mid1]>=ele)
    {
        high = mid1;
    }
    else if (arr[mid2]>ele)
    {
        high = mid2;
    }

    if(arr[mid2]<ele){
        low = mid2+1;
    }
    else if(arr[mid1]<ele)
    {
        low = mid1+1;
    }      
    
	return binarySearchRecursive(arr, len, ele, low, high);
}
int main(){
	int n;
	//cin>>n;
    n=10;
	int arr[n] = {1,2,3,4,5,6,7,8,9,10};
	// for(int i=0; i<n; i++){
	// 	cin>>arr[i];
	// }
	int element=9;
	// cin>>element;
	cout<<"Index using iterative solution: "<<binarySearchIterative(arr, n, element)<<endl;
	// cout<<"Index using recursive solution: "<<binarySearchRecursive(arr, n, element, 0, n)<<endl;
}