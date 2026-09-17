// Search a 2D Matrix
// My Solution

#include <iostream>
#include <vector>
using namespace std;

int justSmall(vector<vector<int>>& arr, int target, int column);

int justBig(vector<vector<int>>& arr, int target, int column);

bool search(vector<vector<int>> &matrix, int target);

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 300;

    cout << search(matrix, target) << endl; 
    return 0;
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

bool search(vector<vector<int>> &matrix, int target) {
    int m = matrix.size() , n = matrix[0].size();
    int leftrow = justSmall(matrix, target, 0);
    int rightrow = justBig(matrix, target, n);

    if(leftrow == rightrow) {
        // then in this row we will apply binary search
        int lo = 0 , hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[leftrow][mid] == target) return true;
            else if (matrix[leftrow][mid] < target) lo = mid + 1;
            else hi = mid - 1; 
        }
        return false;
    } 
    return false;
}

// this solution is wrong and its getting this heap-buffer-overflow error on leetcode and it's wrong.