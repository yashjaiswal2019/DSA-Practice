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
    // we can make an array for the lmax and Rmax
    int size = height.size();
    int ans = 0;
    vector<int> boundary(size, 0);
    boundary[0] = height[0];
    boundary[size -1] = height[size - 1];
    for (int i = 1 ; i < size ; i++){
        boundary[i] = max(boundary[i-1] , height[i]);
    }

    int lastRB = height[size-1];
    for (int j = size - 1 ; j >= 0 ; j--){
        int currRB  = max(lastRB , height[j]);
        boundary[j] = min(lastRB , currRB) - height[j];
        lastRB = currRB;
        if (boundary[j] <= 0) continue;
        ans += boundary[j];
    }

    return ans;
}

// this ans is wrong 