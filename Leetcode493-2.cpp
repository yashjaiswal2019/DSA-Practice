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

int countPairs(vector<int>& nums , int i , int j , int mid) {
    int right = nums.size(), count = 0;
    while (i < mid and j < right) {
        if (nums[i] > 2 * nums[j]) {
            count += mid - i + 1; 
            i++, j++;
        }
        else j++;
    }
    return count;
}

int merge(vector<int> &nums, int left, int right, int mid) {
    // we will create the left halfs and right halfs and we will calculate the pairs efficiently
    int aSize = mid - left + 1, bSize = right - (mid + 1) + 1;

    vector<int> a(aSize , 0);
    vector<int> b(bSize , 0);
    
    for (int i = 0 ; i < aSize ; i++) a[i] = nums[i + left]; 
    for (int i = 0 ; i < bSize ; i++) a[i] = nums[i + mid + 1]; 

    // merging the arrays 
    int i = left , j = mid + 1 , k = left;
    int count = 0;
    count += countPairs(nums , i , j , mid);

    while (i < aSize and j < bSize) {
        if (a[i] > b[j]) nums[k++] = a[i++];
        else nums[k++] = b[j++];
    }

    while (i < aSize) nums[k++] = a[i++];
    while (j < bSize) nums[k++] = b[j++];

    return count;
}

int mergeSort(vector<int> &nums, int left, int right) {
    if (left > right) return 0;

    int ans = 0;
    int mid = left + (right - left) / 2;
    ans += mergeSort(nums, left , mid);
    ans += mergeSort(nums , mid + 1 , right);

    ans += merge(nums , left , right , mid);

    return ans;
}

int reversePairs(vector<int>& nums) {
    // we will use merge Sort algoritm to solve this ques
    int left = 0, right = nums.size() - 1;
    return mergeSort(nums, left , right);
}

// this solution is wrong i dont know why