// practicing the binary search algorithm

// we have to find the index of the minimum element in the given sorted array using the binary search algorithm 
#include <iostream>
using namespace std;

int binarySearch (int *arr , int size , int target);

int main()
{
    int arr[] = {-1 , 0 , 3, 4, 5, 9 , 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "please enter the value of the target element : ";
    cin >> target;
    int result = binarySearch(arr , size , target);

    cout << result << endl;
}

int binarySearch (int *arr , int size , int target){
    int lo = 0 , hi = size -1;

    while (lo <= hi){
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid -1; 
    }

    // if we didn't return a value in the loop it means that element doen't exist in the array
    return -1;
}