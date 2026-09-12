#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &arr , int target);

int main()
{
    vector<int> arr = {3, 1};
    // vector<int> arr = {0 , 1 , 2, 3, 4, 5, 6, 7, 8, 9};
    int traget = 1;

    int result = find(arr , traget);

    cout << result << endl;
    return 0;
}

int find(vector<int> &arr , int target){
    int start = 0 , end = arr.size() - 1;
    
    while (start <= end) {
        // chcking if array is rotated or not 
        // let's cmonsider that array is rotated 
        int mid = start + (end - start) / 2;
        if (arr[mid] >= arr[start]) { // mid is rotated 
            if (arr[mid] == target) return mid;
            else if (arr[mid] > target and arr[start] <= target) end = mid - 1;
            else start = mid + 1;
        }
        else { // mid is not rotated 
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target and arr[end] >= target) start = mid + 1;
            else end = mid - 1;
        }
    }
    return -1; // we didn't find the target in the array
}