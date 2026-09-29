// Trapping Rain Water

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
    // we can use two for Loops to find the lmax and rmax values
    int ans = 0 , size = height.size();
    for (int i = 0  ; i < size ; i++) {
        // loop for lmax
        int Lmax = height[i];
        for (int j = 0 ; j<= i ; j++) {
            Lmax = max(Lmax , height[j]);
        }

        // loop for Rmax 
        int Rmax = height[i];
        for (int k = size - 1 ; k >= i ; k--){
            Rmax = max(Rmax , height[k]);
        }

        // calculating the height 
        int high = min(Lmax , Rmax) - height[i];
        if (high < 0) continue;
        else ans += high;
    }
    return ans;
}

// Time Complexity --> O(n^2);
// space Complexity --> O(1);