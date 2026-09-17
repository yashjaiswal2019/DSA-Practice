#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &arr, int target)
{
    // first we have to find the row in which our target can exist
    int m = arr.size(), n = arr[0].size();
    int row = -1;
    int rlo = 0, rhi = m - 1;
    while (rlo <= rhi)
    {
        int mid = rlo + (rhi - rlo) / 2;
        if (arr[mid][0] <= target and arr[mid][n - 1] >= target){
            row = mid;
            break;
        }
            
        else if (arr[mid][n - 1] < target)
            rlo = mid + 1;
        else
            rhi = mid - 1;
    }

    // now that we have got the row we can apply binary search on this row
    int clo = 0, chi = n - 1;
    while (clo <= chi)
    {
        int mid = clo + (chi - clo) / 2;
        if (arr[row][mid] == target)
            return true;
        else if (arr[row][mid] < target)
            clo = mid + 1;
        else
            chi = mid - 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 300;

    cout << searchMatrix(matrix, target) << endl;
    return 0;
}