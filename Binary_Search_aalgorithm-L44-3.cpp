// binary search algorithm

// find a given target element in the given array using binary search algorithm 
// if found return the elemnt's indiex

#include <iostream>
using namespace std;

int binarySearch(int *arr , int size , int target);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13, 15, 16, 19, 23, 26, 56, 78, 89, 2345, 19999999};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "please enter the value of target : ";
    cin >> target;

    cout << binarySearch(arr , size , target);

    return 0;
}

int binarySearch(int *arr , int size , int target){
    // we have to find an element in the array and return it's index if it exists in the array

    int lo = 0 , hi = size - 1;

    while (lo <= hi){
        int mid = (lo + hi) / 2;
        
        // comparing the mid element with the target element.
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;      // this means that the mid is > target ==> element will be in the left side of the array
    }

    // if we didn't return the value during the loop it means target doesn't exist in the array
    return -1;
}