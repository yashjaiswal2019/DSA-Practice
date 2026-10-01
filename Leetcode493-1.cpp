// 493. Reverse Pairs

// My Bruteforce solution

#include <iostream>
#include <vector>
using namespace std;

int reversePairs(vector<int>& nums);

int main()
{
    vector<int> nums = {1,3,2,3,1};
    cout << reversePairs(nums) << endl;
    return 0;
}

int reversePairs(vector<int>& nums) {
    int pairs = 0 , n = nums.size();
    for (int i = 0 ; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            if (nums[i] > 2 * nums[j]) pairs++;
        }
    }
    return pairs;
}

// time Complexity -> O(n^2)
// space Complexity -> O(1)