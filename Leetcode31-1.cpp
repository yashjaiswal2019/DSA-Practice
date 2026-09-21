// next Permutation
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // we have to find the pivot element
        int pivot = -1;
        int size = nums.size();
        for (int i = size - 2 ; i >= 0 ; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        
        if (pivot == -1){
            reverse(nums.begin() , nums.end());
            return;
        } 
        
        // finding the right most element greater than pivot
        int j = size - 1;
        while (nums[j] <= nums[pivot]) j--;
        swap(nums[pivot] , nums[j]);
        
        reverse(nums.begin() + pivot + 1, nums.end() );

    }
};

// this is my leetcode soln 