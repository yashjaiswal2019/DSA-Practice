// Find the Duplicate Number

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int findDuplicate(vector<int>& nums);

int main() 
{
    vector<int> nums = {1,3,4,2,2};
    cout << findDuplicate(nums) << endl;
}

int findDuplicate(vector<int>& nums) {
    // using the unordered set to store the number
    int size = nums.size();
    unordered_set<int> s;
    for (int i = 0 ; i < size ; i++) {
        if (s.find(nums[i]) != s.end()) return nums[i];
        else s.insert(nums[i]);
    }
    return -1;
}

// Time complexity : O(n)
// Space Complexity : O(n)