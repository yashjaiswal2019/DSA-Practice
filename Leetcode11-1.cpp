// Container With Most Water
// my solution 

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height);

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height);
    return 0;
}

int maxArea(vector<int>& height) {
    int ans = 0, size = height.size(),left = 0, right = size - 1;

    if (size == 2) return min(height[left], height[right]);  // this is obvious

    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right -left;
        int area = w * h;
        ans = max(ans , area);

        // updating the pointers
        (height[left] < height[right]) ? left++ : right--; 
    }
    return ans;
}

// Time Complexity - O(n)
// Space Complexity - O(1)