// Search a 2D Matrix
// My Solution

#include <iostream>
#include <vector>
using namespace std;

int justBig(vector<vector<int>>& arr, int target, int column) {
    // we have to return the index equal to or just bigger than the target
    int lo = 0, hi = arr.size() - 1;
    int result = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid][column] >= target) {
            result = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    return result;
}


int justSmall(vector<vector<int>>& arr, int target, int column) {
    // we have to return the index equal to or just Small than the target
    int lo = 0, hi = arr.size() - 1;
    int result = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid][column] <= target) {
            result = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return result;
}

int main()
{
    vector<vector<int>> arr = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 34;

    cout << justSmall(arr, target, 0) << endl; 
    cout << justBig(arr, target, 2) << endl; 
    return 0;
}