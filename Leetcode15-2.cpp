// 3Sum
// Optimised approach --> using Sorting and two piunters

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums);

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = threeSum(nums);

    // printing the result
    for (vector<int> &vec : result) {
        for (int &ele : vec) {
            cout << ele << ",";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    // sorting the nums array
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int i = 0 ; i < size ; i++) {
        if (i > 0 and nums[i] == nums[i-1]) continue; // for handling duplicate values

        int lo = i + 1, hi = size -1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (sum == 0) {
                // found the triplet
                ans.push_back({nums[i] , nums[lo] , nums[hi]}); 
                // we have to now move the pointers so that other answer dont include these values 
                lo++, hi--; 
            }
            else if (sum < 0) lo++;
            else hi--;
        }
    }
    return ans;
}