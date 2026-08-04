/*  given a rotated sorted array of integers and a target element 
    return the index of the target element if it exists in the array else return -1.
    all elements in the array are distinct.  
*/

// we will use binary search twice to find the element and our time complexity will be of O(2log n) which is O(log n)

#include <iostream>
#include <vector>
using namespace std;

int binarySearch (vector<int> &arr , int target , int lo , int hi);

int minIdx (vector<int> &arr);

int findelement (vector<int> &arr , int target); 

int main()
{
    vector<int> arr = {6, 7, 8, 1, 2, 3, 4, 5};

    int target;
    cout << "please enter the value of the target : ";
    cin >> target;

    int result = findelement(arr , target);

    cout << result << endl;
    return 0;
}

int binarySearch (vector<int> &arr , int target , int lo , int hi){
    // we will use binary search algorithm 

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }

    // if we didn't find the element in the array we will return -1
    return -1;
}

int minIdx (vector<int> &arr){
    // finding the minimum element's index 

    int lo = 0 , hi = arr.size() - 1;

    // checking if array is rotated or not 
    if (arr[lo] < arr[hi]) return lo;
    else {
        while (lo <= hi){
            int mid = lo + (hi - lo) / 2;

            // terminating condition 
            if (arr[mid] > arr[mid + 1]) return mid + 1;
            if (arr[mid] < arr[mid - 1]) return mid;

            if (arr[mid] > arr[lo]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
}

int findelement (vector<int> &arr , int target){
    // we will first find the minimum element's index 
    int min = minIdx(arr);

    // check if array is rotated ?
    if(min == 0) return binarySearch(arr , target , 0 , arr.size() - 1);    // not rotated
    else {
        // checking in which half our element could be present
        if (arr[min] == target) return min;
        else if (arr[min] < target && target < arr[arr.size() -1]) return binarySearch(arr , target , min + 1 , arr.size() - 1);       // have to check right half
        else return binarySearch(arr , target , 0 , min - 1);
    }

    // if we didn't find the element in the array 
    return -1;
}