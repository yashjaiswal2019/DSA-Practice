// 3Sum
// this is BruteForce solution of this problem

#include <iostream>
#include <set>
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

vector<vector<int>> threeSum(vector<int>& nums) {\
    int size = nums.size(); 
    set<vector<int>> s;
    vector<vector<int>> ans;
    for (int i = 0; i < size ; i++) {
        for (int j = i+1 ; j < size ; j++) {
            for (int k = j+1; k < size ; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    // storing the triplet now
                    vector<int> trip = {nums[i] ,nums[j] , nums[k]};
                    sort(trip.begin(), trip.end());
                    if (s.find(trip) == s.end()) {
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    return ans;
}