// 239. Sliding Window Maximum
// My Solution --> thinking of bruteForce 

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k);

int main() 
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums , k);
    // printing the Ans
    for (int &ele : ans) cout << ele << " ";
    cout << endl;
    return 0;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size(), left = 0 , right = k - 1;
    vector<int> ans;
    while (right != n) {
        int windowMax = INT_MIN;
        for (int i = left ; i <= right ; i++) {
            if (nums[i] > windowMax) windowMax = nums[i];
        }
        
        ans.push_back(windowMax);
        left++, right++;
    }
    return ans;
}

// Time Comlexity --> O(n^2)
// Space Complexity --> O(1)