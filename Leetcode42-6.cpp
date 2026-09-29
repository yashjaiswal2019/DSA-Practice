// trapping the rainWater
// this is the bruteforce Soln. for Practice.
// Time Comp = O(n)
// Space Comp = O(n)

#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height);

int main() 
{
    vector<int> height = {4,2,0,3,2,5};
    cout << trap(height) << endl;
    return 0;
}

int trap(vector<int>& height) {
    // we will use two arrays for storing the Lmax and Rmax for each of the Element
    int n = height.size(), ans = 0;

    // for Lmax
    vector<int> Lmax(n);
    Lmax[0] = height[0];
    for (int i = 1 ; i < n ; i++) {
        Lmax[i] = max(Lmax[i-1] , height[i]);
    }

    // For Rmax
    vector<int> Rmax(n);
    Rmax[n-1] = height[n-1];
    for (int i = n-2 ; i >= 0 ; i--) {
        Rmax[i] = max(Rmax[i+1] , height[i]);
    }

    // loop for making the ans
    for (int i = 0 ; i < n ; i++) {
        int currWater = min(Rmax[i] , Lmax[i]) - height[i];
        if (currWater <= 0) continue;
        else ans += currWater;
    }
    return ans;
}