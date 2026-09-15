// we have to return the number appeared only once in the array

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums);

int main()
{
    vector<int> nums = {4,1,2,1,2};

    cout << singleNumber(nums) << endl;
    return 0;

}

int singleNumber(vector<int> &nums) {
    // We can use XOR to solve this 
    // a^a == 0 and 0^x == x --> we can take xor of whole array together

    int ans = 0;
    for (int &ele : nums) ans = ans^ele;
    return ans; 
}