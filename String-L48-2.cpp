// learning how indexing works in strings 

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "yash jayasaval";

    for (char ele : str){
        cout << ele << " ";
    }
    cout << endl;

    cout << str[0] << " " << str[1] << endl; 
    return 0;
}