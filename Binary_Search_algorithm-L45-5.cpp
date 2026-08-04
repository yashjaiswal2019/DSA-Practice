/**we are given a sorted rotated array.
 * we have to find the minimum element in the array and return it's index.
 * it is guranted that array contains unique elements 
*/

// practicing sorted rotated array ques again 

#include <iostream>
#include <vector>
using namespace std;

int minIdx (vector<int> &arr);

int main()
{
    vector<int> arr = {6, 7 , 2, 3, 4, 5};
    
    int result = minIdx(arr);

    cout << result << endl;

    return 0;
}

int minIdx (vector<int> &arr){
    // we will use binary search algorithm to solve this problem

    int lo = 0, hi = arr.size() - 1;

    // have to check if array is rotated or not first 
    if(arr[lo] < arr[hi]) return lo;
    else {
        while (lo <= hi){
            int mid = lo + (hi - lo) / 2;
            // have to write the terminating condition
            if (arr[mid] > arr[mid + 1]) return mid + 1;
            if (arr[mid] < arr[mid - 1]) return mid;

            if (arr[mid] > arr[lo]) lo = mid + 1;
            else hi = mid - 1;
        }
    }

    return -1;
}