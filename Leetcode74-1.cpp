// Search a 2D Matrix
// My Solution

#include <iostream>
#include <vector>
using namespace std;

bool search(vector<vector<int>> &matrix, int target);

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 34;

    cout << search(matrix, target) << endl; 
    return 0;
}

bool search(vector<vector<int>> &matrix, int target) {
    int m = matrix.size() , n = matrix[0].size();
    for (int i = 0 ; i < m ; i++) {
        if (matrix[i][0] <= target and matrix[i][n-1] >= target) {
            for (int j = 0 ; j < n ; j++) {
                if (matrix[i][j] == target) return true;
            }
        }
    }
    return false;
}
// this code reached restriction we have to write a soltion of 