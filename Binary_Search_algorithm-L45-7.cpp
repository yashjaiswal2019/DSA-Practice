/*  given a rotated sorted array of integers and a target element 
    return the index of the target element if it exists in the array else return -1.
    all elements in the array are distinct.  
*/

#include <iostream>
#include <vector>
using namespace std;

int binarySearchRotatedSorted(vector<int> arr , int target);

int main()
{
    vector<int> arr = {6, 7, 8, 1, 2, 3, 4, 5};

    int target;
    cout << "please enter the value of target : ";
    cin >> target;
    
    int result = binarySearchRotatedSorted(arr , target);
    cout << result << endl;
    return 0;
}

int binarySearchRotatedSorted(vector<int> arr , int target){
    // we will use binary search algorithm to find the element 
    
    int lo = 0 , hi = arr.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;

        if (arr[mid] > arr[lo]){
            if(target >= arr[lo] and target <= arr[mid]) hi = mid - 1;
            else lo = mid + 1;
        }
        else{
            if (target >= arr[mid] and target <= arr[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }

    return -1;      // In case we didn't find the element in the array.
}