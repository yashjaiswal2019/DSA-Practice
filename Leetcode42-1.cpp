// Trapping Rain Water

#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height);

int main() 
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;
    return 0;
}

int Lmax(vector<int>& height, int idx) {
    int i = 0;
    int ans = 0;
    while (i < idx) {
        if (height[i] > height[idx]) ans = max(height[i] , ans);
        i++;
    }
    return ans;
}

int Rmax(vector<int>& height, int idx) {
    int i = height.size() - 1;
    int ans = 0;
    while (i > idx) {
        if (height[i] > height[idx]) ans = max(height[i] , ans) ;
        i--;
    }
    return ans;
}

int trap(vector<int>& height) {
    // we have to find the left max and right max for every indec of heights array
    int size = height.size() , ans = 0;
    for (int i = 0 ; i < size ; i++) {
        int left = Lmax(height , i);
        int right = Lmax(height , i); 

        int high = min(left , right) - height[i];
        // if (high < 0) continue;
        ans += high;
    }
    return ans;
}

// this solution is wrong and I don't know Why ?