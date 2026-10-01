// 84. Largest Rectangle in Histogram

// Optimal Solution
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights);

int main()
{
    vector<int> heights = {1 , 2};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size() , ans = 0;
    // making the right boundary array
    stack<int> s;
    vector<int> right(n , 0);
    for (int i = n-1 ; i >= 0 ; i--) {
        while (s.size() > 0 and heights[s.top()] >= heights[i]) s.pop();
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    while (s.empty() != true) s.pop(); // emptying the stack

    // making the left boundary array
    vector<int> left(n , 0);
    for (int i = 0 ; i < n ; i++) {
        while (s.size() > 0 and heights[s.top()] >= heights[i]) s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // finding the ans 
    for (int i = 0 ; i < n ; i++) {
        int currArea = heights[i] * (right[i] - left[i] - 1);
        ans = max(currArea , ans);
    }
    return ans;
}

// Time Complexity -> O(n)
// Space Complexity -> O(n)