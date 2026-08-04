/**we are given a sorted rotated array.
 * we have to find the minimum element in the array and return it's index.
 * it is guranted that array contains unique elements 
*/

#include <iostream>
#include <vector>
using namespace std;

int minIdx (vector<int> &arr);

int main()
{
    vector <int> arr = {6, 7 , 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    
    int result = minIdx(arr);

    cout << result << endl;
    return 0;
}

int minIdx (vector<int> &arr){
    /**Time complexity = O(log n)
     * Space complexity = O(1)
    */

    int lo = 0 , hi = arr.size() - 1;

    if (arr[lo] < arr[hi] ) return arr[lo];     // sorted array
    else {
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (arr[mid] > arr[mid + 1]) return mid + 1;
            if(arr[mid] < arr[mid - 1]) return mid;
            else {
                if (arr[mid] > arr[lo]) lo = mid + 1;
                else hi = mid - 1;      // condition--> if (arr[mid] < arr[lo]) hi = mid -1;
            }
        }
    }

    return -1;
}