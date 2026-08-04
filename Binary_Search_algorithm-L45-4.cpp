/**we are given a sorted rotated array.
 * we have to find the minimum element in the array and return it's index.
 * it is guranted that array contains unique elements 
*/

// practicing sorted rotated array ques again 

#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &arr);

int main()
{
    vector <int> arr = {6, 7 , 2, 3, 4, 5};
    
    int result = findMin(arr);

    cout << "index of minimum element is : " << result << endl;
    
    return 0;
}

int findMin(vector<int> &arr){
    /**
     * Time complexity = O(log n) 
     * Space complexity = O(1)
    */

    int lo = 0 , hi = arr.size() - 1;

    if (arr.size() == 1) return 0;
    if (arr[lo] < arr[hi]) return lo;       // array is sorted only
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