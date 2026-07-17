// practicing the binary search algorithm 

#include <iostream>
using namespace std;

int binarySearch(int *arr , int size , int taregt);

int main()
{
    int arr[] = {-1 , 0 , 3, 4, 5, 9 , 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "please enter the target : ";
    cin >> target;

    cout << binarySearch(arr , size , target) << endl;

    return 0;
}

int binarySearch(int *arr , int size , int target){
    // binary search algorithm 

    int lo = 0 , hi = size - 1;
    
    while (lo <= hi){
        int mid = lo + (hi - lo) / 2;

        if(arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }

    return -1;
}