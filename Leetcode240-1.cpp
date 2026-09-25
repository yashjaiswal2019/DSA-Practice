// Search a 2D Matrix II

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target);

int main() 
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
}

bool searchMatrix(vector<vector<int>> &arr, int target)
{
    // we can solve this ques as we choose the top-right element of matrix as mid and traverse according to that
    int m = arr.size(), n = arr[0].size();
    int r = 0, c = n - 1;
    while (c >= 0 and r < m)
    {
        if (target == arr[r][c])
            return true;
        else if (target < arr[r][c])
            c--;
        else
            r++;
    }
    return false;
}