// a) Given a sorted array of integers, write a program to find an element in it and return its index. The algorithm should complete the task in O(log2n) time, where n is the number of elements in the array. Implement your algorithm through both iterative and recursive approach. Take care of the following edge cases:
// •	If the element does not exist, return the index of the next smallest number just greater than the element.
// •	If the element is greater than all the integers in the array, return the length of the array
// •	If multiple copies of the element occur, return the first occurrence

#include<iostream>
#include<stdio.h>

using namespace std;

int binarySearchIterative(int* arr, int len, int ele){
    int low = 0, high = len;
    int mid;
    while (low<high)
    {
		mid = (low+high)/2;
        if(arr[mid] >= ele){
            /* since we have to find the first occurence, we keep moving left with the hope that the element occurs again */
			high = mid;
		}
		else {
			low = mid + 1;
		}        
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
	int mid = (low+high)/2;
	if(arr[mid] >= ele){
		return binarySearchRecursive(arr, len, ele, low, mid);
	}
	return binarySearchRecursive(arr, len, ele, mid+1, high);
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int element;
	cin>>element;
	cout<<"Index using iterative solution: "<<binarySearchIterative(arr, n, 		element)<<endl;
	cout<<"Index using recursive solution: "<<binarySearchRecursive(arr, n, 		element, 0, n)<<endl;
}