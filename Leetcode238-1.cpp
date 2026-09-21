// product of array except self

#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums);

int main()
{
    vector<int> nums = {4,3,2,1,2};
    
    vector<int> result = productExceptSelf(nums);

    for (int &ele : result) cout << ele << " ";
    return 0;

}

vector<int> productExceptSelf(vector<int>& nums) {
    // we can observe that if there are more than one zero in the nums then all elements will be zero in ans array so we can track that 
    int zeroCount = 0;
    if (nums[0] == 0) zeroCount++;

    // making the ans array as prefix product array
    int n = nums.size();
    vector<int> ans(n, 1);

    int prefix = nums[0];
    for (int i = 1 ; i < n ; i++) {
        if (nums[i] == 0) zeroCount++;
        ans[i] = prefix;
        prefix *= nums[i];
    }

    if (zeroCount >= 2) return vector<int> (n, 0);

    // traversing the nums backwards to make suffix from n-2 idx
    int suffix = nums[n-1];
    for (int i = n-2 ; i >= 0 ; i--) {
        ans[i] *= suffix;
        suffix *= nums[i];
        // if (i == 0) ans[i] = suffix;
    }

    return ans;
}