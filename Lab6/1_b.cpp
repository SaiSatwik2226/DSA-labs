// a) Given a sorted array of integers, write a program to find an element in it and return its index. The algorithm should complete the task in O(log2n) time, where n is the number of elements in the array. Implement your algorithm through both iterative and recursive approach. Take care of the following edge cases:
// •	If the element does not exist, return the index of the next smallest number just greater than the element.
// •	If the element is greater than all the integers in the array, return the length of the array
// •	If multiple copies of the element occur, return the first occurrence

#include<iostream>
#include<stdio.h>

using namespace std;

int binarySearchIterative(int* arr, int len, int ele){
    int low = 0, high = len-1;
    int mid1,mid2;
    while (high-low>3)
    {
        mid1 = (low+high)/3;
        mid2 = 2*(low+high)/3;
        if (arr[mid1]>=ele)
        {
            high = mid1;
        }
        if (arr[mid2]>=ele && ele>arr[mid1])
        {
            high = mid2;
            low = mid1+1;
        }
        if(arr[mid2]<ele){
            low = mid2+1;
        }             
        // cout<<low<<" "<<high<<endl;
    }
    if(arr[low]==ele)
		return low+1;
    else if(arr[low+1]==ele)
        return low+2;
    else if(arr[high]==ele)
        return high;
	return -1;
}

int binarySearchRecursive(int* arr, int len, int ele, int low, int high){
	//base case
	if(high-low>3){
		if(arr[low]==ele)
		return low+1;
        else if(arr[low+1]==ele)
            return low+2;
        else if(arr[high]==ele)
            return high;
        return -1;
	}
    int mid1 = (low+high)/3;
    int mid2 = 2*(low+high)/3;
    if (arr[mid1]>=ele)
    {
        high = mid1;
    }
    if (arr[mid2]>=ele && ele>arr[mid1])
    {
        high = mid2;
        low = mid1+1;
    }
    if(arr[mid2]<ele){
        low = mid2+1;
    }
	return binarySearchRecursive(arr, len, ele, low, high);
}
int main(){
	int n;
    n=10;
	int arr[n] = {1,2,3,4,5,6,8,9,10};
	int element=7;
	// cin>>element;
    int x = binarySearchIterative(arr, n, element);
    if (x>0)
	cout<<"Index using iterative solution: "<<x<<endl;
    else
    cout<<"Not Found"<<endl;
    
	cout<<"Index using recursive solution: "<<binarySearchRecursive(arr, n, element, 0, n)<<endl;
}