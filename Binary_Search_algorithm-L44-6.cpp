// writing the binary search algorithm when a sorted array is given 

#include <iostream>
using namespace std;

int binarySearch(int *arr , int size , int target);

int main()
{
    int arr[] = {1, 9, 13, 15, 18, 22, 33, 40};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "please enter the value of X : ";
    cin >> target;

    int result = binarySearch(arr , size , target);
    cout << result << endl;

    return 0;
}

int binarySearch(int *arr, int size, int target)
{
    int lo = 0 , hi = size -1;

    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;

        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }

    return -1;
}