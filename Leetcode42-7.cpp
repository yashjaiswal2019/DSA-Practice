// trapping the rainWater
// this is the bruteforce Soln. for Practice.
// Time Comp = O(n)
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
    // we will use the two pointers approach to find the ans 
    int ans = 0 , n = height.size();
    int left = 0 , right = n-1;
    int Lmax = -1 , Rmax = -1;

    while (left < right) {
        Lmax = max(Lmax , height[left]);
        Rmax = max(Rmax , height[right]);

        if (Lmax < Rmax) {
            ans += Lmax - height[left];
            left++;
        }
        else {
            ans += Rmax - height[right];
            right--;
        }
    }
    return ans;
}