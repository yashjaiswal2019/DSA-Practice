// practicing the binary search algorithm using recursion.

#include <iostream>
#include <vector>
using namespace std;

int binarySearch (vector<int> arr , int target , int start , int end);

int main()
{
    vector<int> arr = {-1, 0, 3, 5, 9, 12};
    int target;

    cout << "please enter target : ";
    cin >> target;

    cout << binarySearch(arr , target , 0 , arr.size() - 1) << endl;
    return 0;

}

int binarySearch (vector<int> arr , int target , int start , int end){
    // base case 
    if (start > end) return -1;      // element doesn't exist in the array

    int mid = start + (end - start) / 2;

    if (arr[mid] == target) return mid;
    else if (target > arr[mid]) return binarySearch(arr , target , mid + 1 , end);  // search second half 
    else return binarySearch(arr , target , start , mid - 1);       // search first half

    
}

// Time complexity = O(log n).
// Space complexity = O(log n).