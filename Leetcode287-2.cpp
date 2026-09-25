// Find the Duplicate Number
// using the slow-fast approach

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
    int slow = nums[0] , fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}