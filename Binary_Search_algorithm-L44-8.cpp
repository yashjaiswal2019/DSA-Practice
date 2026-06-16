// practicing the binary search algorithm

// we are given a sorted integer array int ascending order and 
// we have to return the index of the target element if it exists in the array
// else return -1

//using the vector.

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums , int target);

int main()
{
    vector<int> arr = {1, 9, 13, 15, 18, 22, 33, 40};

    int target;
    cout << "please enter the value of target : ";
    cin >> target;
    
    cout << search(arr , target) << endl;

    return 0;
}


int search(vector<int> &nums , int target){
    // using the binary search algo.
    int lo = 0 , hi = nums.size() - 1;

    while (lo <= hi){
        int mid = lo + (hi - lo) / 2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) lo = mid + 1;
        else                        hi = mid - 1;
    }

    return -1;
}