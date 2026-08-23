// how we use reverse string function in the strings 
// how to use substr fn in string 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str = "yash";

    reverse(str.begin() , str.end());
    cout << str << endl;

    cout << str.substr(1 , 3) << endl;
    cout << str.substr(2) << endl;
    return 0;
}