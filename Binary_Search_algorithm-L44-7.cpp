/**find the square root of a given non negative value of X. 
 * round it off to the nearest floor value of integer
 * input = 4 
 * output = 2
 * 
 * input = 11
 * output = 3
  */

#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "please enter the value of X :";
    cin >> x;
    
    // we will use kind of binary search algo as for a given value x 
    // its square root lies between 1 and x 

    int ans = -1;
    int start = 1 , end = x;

    while (start <= end){
        int mid = end + (start - end) / 2;

        if (mid * mid <= x){
            ans = mid;
            start = mid + 1;
        }
        // else if (mid * mid < x) start = mid + 1;    // we didnt need this seprately as our first condition covers this case as well 
        //                                                still have to update the value in our ans variable.
        else end = mid - 1; 
    }

    cout << ans << endl;
    return 0;
}