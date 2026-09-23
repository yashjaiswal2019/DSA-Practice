// Subarray Sum Equals K

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k);

int main() 
{
    vector<int> arr = {1,2,3};
    int k = 3;

    int result = subarraySum(arr , k);
    cout << result << endl;
    return 0;
}

int subarraySum(vector<int>& nums, int k) {
    // we can make prefix sum array and use a hashmap to track the values 
    int temp = 0 , n = nums.size(), count = 0;
    vector<int> ps(n , 0);
    for (int i = 0 ; i < n ; i++) {
        temp += nums[i];
        ps[i] = temp;
    }

    unordered_map<int , int> m;
    for (int j = 0 ; j < n ; j++) {
        if (ps[j] == k) count++;
        
        int val = ps[j] - k;
        if (m.find(val) != m.end()) {
            count += m[val];
        }

        // inserting this val for suture use 
        if (m.find(ps[j]) == m.end()) m[ps[j]] = 0;
        m[ps[j]]++;
    }
    return count;
}