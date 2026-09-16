// Find Missing and Repeated Values

// we are given a square matric of n x n and we have to return the missing and repeating value
#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissingAndRepeat(vector<vector<int>>& grid , int n);

int main()
{
    vector<vector<int>> grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    int n = 3;

    vector<int> result = findMissingAndRepeat(grid, n);
    
    for (int &ele : result) cout << ele << " ";
}

vector<int> findMissingAndRepeat(vector<vector<int>>& grid, int n){
    // let's make a freq array and we will update the value in the array
    vector<int> freq(n*n + 1, 0);

    for(int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            freq[grid[i][j]]++;
        }
    }
    int repeat = -1, missing = -1;

    // lets traverse the array
    int freqSize = freq.size();
    for (int i = 0 ; i < freqSize ; i++) {
        if (freq[i] == 0) missing = i;
        if(freq[i] == 2) repeat = i;
    }
    return {missing, repeat};
}