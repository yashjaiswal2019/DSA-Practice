// now binary search using the recursion.

#include <iostream>
using namespace std;

int binarySearch(int *arr , int start , int end , int target);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13, 15, 16, 19, 23, 26, 56, 78, 89, 2345, 19999999};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "please enter the value of target : ";
    cin >> target;

    int result = binarySearch(arr , 0 , size -1 , target);
    cout << result << endl;

    return 0;
}

int binarySearch(int *arr , int start , int end , int target){
    // for making the binary search using the recursion 

    // if we didn't find the element in the array
    if(start > end) return -1;

    // base case 
    int mid = (start + end) / 2;
    
    // assumption and self work.
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearch(arr , mid + 1 , end , target);
    else return binarySearch(arr , start , mid - 1 , target);
}