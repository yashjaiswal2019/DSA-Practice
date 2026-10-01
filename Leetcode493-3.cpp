// 493. Reverse Pairs

// optimal solution

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

void merge(vector<int>& nums, int lo , int mid, int hi) {
    // we now just have to merge the array now
    int n = nums.size();
    vector<int> temp;
    int i = lo , j = mid + 1;

    while (i <= mid and j <= hi) {
        if (nums[i] < nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }
    while (j <= hi) {
        temp.push_back(nums[j]);
        j++;
    }
    

    // copying the elements back to the given array
    int tempSize = temp.size();
    for (int i = 0 ; i < tempSize ; i++) nums[i + lo] = temp[i];
}

int countPair (vector<int>& nums, int lo , int mid , int hi) {
    int i = lo , j = mid + 1;
    int count = 0;
    while (i <= mid and j <= hi) {
        if (nums[i] > (long long) 2 * nums[j]){
            count += mid - i + 1;
            j++;
        }
        else i++;
    }

    return count;
}

int mergeSort(vector<int>& nums , int lo , int hi) {
    if (lo >= hi) return 0;

    int mid = lo + (hi - lo) / 2;
    int count = 0;
    count += mergeSort(nums , lo , mid);
    count += mergeSort(nums , mid + 1 , hi);
    count += countPair(nums , lo , mid , hi);

    merge(nums , lo , mid , hi);
    return count;
}

int reversePairs(vector<int>& nums) {
    // we will use the mergeSort Algorithm to find the pairs efficiently during the merge Step
    return mergeSort(nums, 0 , nums.size()-1);
}