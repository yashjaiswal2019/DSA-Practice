// 4 Sum 
// My Solution resonatiing with the solution of three sum

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);

int main()
{
    vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    int target = 0;

    // printing the ans
    vector<vector<int>> ans = fourSum(nums, target);
    for (vector<int> &arr : ans) {
        for (int &ele : arr) {
            cout <<  ele << ",";
        }
        cout << endl;
    }
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // sorting the array First
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    // now looping for the elements 
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        // looping for repeating values
        if (i > 0 and nums[i] == nums[i-1]) continue;

        for (int j = i + 1 ; j < n ; j++) {
            // looping for repeating values
            if (j > i+1 and nums[j] == nums[j-1]) continue;

            // we have to prevent the number from overflowing the integer we have to change the target accordingly
            // we can store the currSum in long long datatype

            int st = j + 1 , end = n - 1;
            while (st < end) {
                long long currSum = (long long)nums[i] + nums[j] + nums[st] + nums[end];
                if (currSum < target) st++;
                else if (currSum > target) end--;
                else {
                    ans.push_back({nums[i] , nums[j] , nums[st] , nums[end]});
                    st++, end--;

                    // looping for repeating values
                    while (st < end and nums[st] == nums[st-1]) st++;
                }
            }
        }
    }
    return ans;
}