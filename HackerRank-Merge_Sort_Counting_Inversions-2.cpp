// Merge Sort: Counting Inversions
// problem link : https://www.hackerrank.com/challenges/ctci-merge-sort/problem

// optimised solutuion

#include <iostream>
#include <vector>
using namespace std;

int merge (vector<int>& arr, int start, int mid , int end);

int mergeSort (vector<int>& arr , int left , int right);

int countInversions (vector<int>& arr);

int main() 
{
    vector<int> arr = {6, 3, 5, 2, 7};
    
    int result = countInversions(arr);
    cout << result << endl;
    return 0;
}

int merge (vector<int>& arr, int start, int mid , int end) {
    // we have to write the merge fn 
    int inversions = 0;
    int i = start , j = mid + 1;
    vector<int> temp;
    while (i <= mid  and  j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            inversions += mid - i + 1;
            j++;
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= end) temp.push_back(arr[j++]);

    for (int idx = 0 ; idx <= temp.size() ; idx++) arr[start + idx] = temp[idx];

    return inversions;
}

int mergeSort (vector<int>& arr , int left , int right) {
    // let's write merge sort fn 
    if (left > right) return 0;
    int ans = 0;
    if  (left < right)
    {
        int mid = left + (right - left) / 2;
        ans += mergeSort(arr, left, mid);
        ans += mergeSort(arr, mid + 1, right);
        ans += merge(arr, left, mid, right);
        return ans;
    }
    else return 0;
    
}

int countInversions (vector<int>& arr) {
    return mergeSort(arr , 0 , arr.size() - 1);
}