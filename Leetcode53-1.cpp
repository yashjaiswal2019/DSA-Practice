// Maximum Subarray
// Bruteforce approach --> we find every possible subarray and calculate it sum

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int sum = INT32_MIN;
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int size = arr.size();
    for (int i = 0; i < size ; i++) {
        int currSum = 0;
        for (int j = i ; j < size ; j++) {
            currSum += arr[j];
            sum = max(sum, currSum);
        }
    }

    cout << sum << endl;
}