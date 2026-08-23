/**trying to learn the basics of Strings
 * How a string is defined.
 * How we create a string.
 * How we take string as an input from the user.
*/

#include <iostream>
#include <string>       // have to include this header file to use string in code 
using namespace std;

int main()
{
    // method 1 of defining
    string name = "Yash Jayasaval";

    // method 2 of defining 
    string name2("Yash");

    // lets print these strings 
    cout << name << endl;
    cout << name2 << endl;

    // now taking string as an input from the user 
    string str;

    cin >> str;
    cout << str << endl;
    // if our string havae white space our cin operator will stop taking input at that point 
    
    // to fix that 
    string str2;
    getline(cin , str2);
    cout << str2 << endl;

    return 0;

}