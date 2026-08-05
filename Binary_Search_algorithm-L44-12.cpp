// practicing the binary search algorithm

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr , int target);

int main()
{
    vector<int> arr = {-1 , 0 , 3, 4, 5, 9, 12};
    
    int target;
    cout << "please enter the target : ";
    cin >> target;

    cout << binarySearch(arr , target) << endl;
    return 0;
}

int binarySearch(vector<int> &arr , int target){
    int st = 0 , end = arr.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if(arr[mid] == target) return mid;
        else if (arr[mid] < target) st = mid + 1;
        else end = mid - 1;
    }

    return -1;  // if elements doesn't exist in the array.
}

// Time complexity = O(log n).
// space complexity = O(1).