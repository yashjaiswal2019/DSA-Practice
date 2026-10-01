// 84. Largest Rectangle in Histogram

// my Solution --> Brute force
#include <iostream>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int>& heights);

int main()
{
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}

int largestRectangleArea(vector<int>& heights) {
    // this is my Bruteforce solution
    int n = heights.size(), maxArea = 0;
    for (int i = 0 ; i < n ; i++){
        int minHeight = heights[i];
        for (int j = i ; j < n ; j++){
            minHeight = min(minHeight , heights[j]);
            int width = j - i + 1;
            int currArea = minHeight * width;
            maxArea = max(maxArea , currArea);
        }
    }
    return maxArea;
}

// Time Complexity -> O(n^2)
// space Complexity -> O(1)