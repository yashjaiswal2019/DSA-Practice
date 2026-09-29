// trapping the rainWater
// this is the bruteforce Soln. for Practice.
// Time Comp= O(n^2)
// Space Comp = O(1)

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
    int ans = 0, n = height.size();
    for (int i = 0 ; i < n ; i++) {
        // Left Bound
        int Lmax = height[i];
        for (int j = 0 ; j <= i ; j++){
            Lmax = max(height[j] , Lmax);
        }

        // right Bound
        int Rmax = height[i];
        for (int k = n-1 ; k >= i ; k--){
            Rmax = max(height[k] , Rmax);
        }

        // finding the area of water that Particular cell can Store 
        int waterTrapped = min(Lmax , Rmax) - height[i];
        if (waterTrapped <= 0) continue;
        else ans += waterTrapped;
    }
    return ans;
}