// Merge Sort: Counting Inversions
// problem link : https://www.hackerrank.com/challenges/ctci-merge-sort/problem

#include <iostream>
#include <vector>
using namespace std;

int countInversions (vector<int>& arr);

int main() 
{
    vector<int> arr = {6, 3, 5, 2, 7};
    
    int result = countInversions(arr);
    cout << result << endl;
    return 0;
}

int countInversions (vector<int>& arr) {
    // brute force approach 
    // we can use nested loops 
    int inversions = 0, size = arr.size();
    for (int i = 0 ; i < size ; i++) {
        for (int j = i + 1 ; j < size ; j++) {
            if (arr[i] > arr[j]) inversions++;
        }
    }
    return inversions;
}