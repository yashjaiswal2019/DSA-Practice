// 239. Sliding Window Maximum
// My Solution --> thinking of bruteForce 

#include <iostream>
#include <deque>
#include <algorithm>
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
    deque<int> dq;
    int n = nums.size(); 
    vector<int> result;


    // Analysing the first Window
    for (int i = 0 ; i < k ; i++) {
        // pushing the viable elements in the deque
        while (dq.size() > 0 and nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
    }

    // now finding the maximum sliding window for other elements
    for (int i = k ; i < n ; i++) {
        // pushing the ans from dq to result array
        result.push_back(nums[dq.front()]);

        // removing the elements that are not a part of current window 
        while (dq.size() > 0 and dq.front() < i - k + 1) dq.pop_front();

        // now we have to only store viable elements in the dq
        while (dq.size() > 0 and nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
    }

    // now the ans of last window is stored in the dq
    result.push_back(nums[dq.front()]);

    return result;
}