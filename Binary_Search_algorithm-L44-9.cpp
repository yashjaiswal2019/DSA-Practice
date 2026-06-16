// practicing the binary search algorithm

// we are given a sorted integer array int ascending order and 
// we have to return the index of the target element if it exists in the array
// else return -1

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &nums , int target);

int main()
{
    vector<int> nums = {1, 9, 13, 15, 18, 22, 33, 40};
    
    int target;
    cout << "please enter the target value : ";
    cin >> target;

    cout << binarySearch(nums , target) << endl;

    return 0;
}

int binarySearch(vector<int> &nums , int target){
    // we will use binary search algorithm to find the target element in the nums array
    int lo = 0 , hi = nums.size() - 1;

    while (lo <= hi){
        int mid = lo + (hi - lo) / 2;

        if(nums[mid] == target) return mid;
        else if (nums[mid] < target) lo = mid + 1;
        else hi = mid - 1; 
    }

    return -1;      // if taregt element is not found in the nums array.
}