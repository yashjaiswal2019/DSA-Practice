// given two sorted arrays , write a program to merge them in a sorted manner

#include <iostream>
using namespace std;

int main()
{
    int num1[] = {5 , 8, 10};
    int num2[] = {2 , 7, 8};

    int size1 = sizeof(num1) / sizeof(num1[0]);
    int size2 = sizeof(num2) / sizeof(num2[0]);

    int size3 = size1 + size2;

    int ans[size3];

    int ptr1 = 0 , ptr2 = 0 , ptr3 = 0;

    while (ptr1 < size1 and ptr2 < size2){
        if(num1[ptr1] < num2[ptr2]) ans[ptr3++] = num1[ptr1++];
        else ans[ptr3++] = num2[ptr2++];
    }

    // filling in the elements left after one element is exhausted 

    while (ptr1 < size1) ans[ptr3++] = num1[ptr1++];
    while (ptr2 < size2) ans[ptr3++] = num2[ptr2++];
    
    // printing the ans array
    for (int &ele : ans){
        cout << ele << " ";
    }

    return 0;
}