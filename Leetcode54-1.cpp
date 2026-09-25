// Spiral Matrix

// my solution 

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main() 
{
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<int> ans = spiralOrder(matrix);
    
    // printing the array
    for (int &ele : ans) cout << ele << " ";
    return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    // let's use 4 pointers top , bottom , left , right
    int m = matrix.size() , n = matrix[0].size();
    int top = 0 , bottom = m - 1 , left = 0 , right = n - 1; 
    vector<int> ans(m * n);
    int dir =  0 , idx = 0;
    // we can use switch case for the direction or we may even use if else 
    // 0 --> right , 1 --> down , 2--> left , 3 --> up

    while (left <= right and top <= bottom){
        if (dir == 0) {
            for (int i = left ; i <= right ; i++) ans[idx++] = matrix[top][i];
            top++ , dir++;
        }
        else if (dir == 1) {
            for (int i = top ; i <= bottom ; i++) ans[idx++] = matrix[i][right];
            right-- , dir++;
        }
        else if (dir == 2) {
            for (int i = right ; i >= left ; i--) ans[idx++] = matrix[bottom][i];
            bottom-- , dir++;
        }
        else {
            for (int i = bottom ; i >= top ; i--) ans[idx++] = matrix[i][left];
            left++ , dir++;
        }
        dir = dir % 4;
    }
    return ans;
}