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
    // we have to find the left max and right max for every index of heights array
    int size = height.size() , ans = 0;
    for (int i = 0 ; i < size ; i++) {
       int j = 0 , Lmax = 0;
       while (j <= i) {
        Lmax = max(height[j] , height[i]);
        j++;
       }

       int k = size - 1 , Rmax = 0;
       while (k >= i) {
        Rmax = max(height[k], height[i]);
        k--;
       }

       int high = min(Rmax , Lmax) - height[i];
       ans += high;
    }
    return ans;
}

// this solution is also wrong and I don't know why ?