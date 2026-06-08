// binary search algorithm

// find a given target element in the given array using binary search algorithm 
// if found return the elemnt's indiex

// This time using for loop for acessing the data inside the array.

#include <iostream>
using namespace std;

int binarySearch (int *arr , int size , int target);

int main()
{
    int arr[] = {1, 9, 13, 15, 18, 22, 33, 40};
    
    cout << "please enter the Target element : ";
    int target;
    cin >> target;

    int size = sizeof(arr) / sizeof(arr[0]);

    int ans = binarySearch(arr , size , target);

    cout << ans << endl;

    return 0;
}

int binarySearch (int *arr , int size , int target){
    int lo = 0 , hi = size - 1;

    while ( lo <= hi){
        int mid = (lo + hi) / 2;

        // checking the value at the mid.
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }

    // if we didn't hit the arr[mid] == target case then it doesn't exist in the array.
    return -1;
}