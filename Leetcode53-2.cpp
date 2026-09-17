// Maximum Subarray
// Kadane's Algorithm 

#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> &arr);

int main()
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    
    cout << maxSubarraySum(arr) << endl;
    return 0;
}

int maxSubarraySum(vector<int> &arr){
    int maxSum = INT32_MIN, currSum = 0;;
    for (int &ele : arr) {
        currSum += ele;
        if (maxSum < currSum) maxSum = currSum;
        if(currSum < 0) currSum = 0;
    }
    return maxSum;
}