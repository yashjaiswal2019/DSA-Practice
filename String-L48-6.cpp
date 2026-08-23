// I am practicing the count sort algorithm , because it has been a long time 
// and i have to use that in a ques 

#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &arr);

int main()
{
    vector<int> arr = {2 , 5, 4, 1, 2, 4, 5, 6};
    
    countSort(arr);
    
    // printing the sorted array
    for (int &ele : arr) cout << ele << " ";
    return 0;
}

void countSort(vector<int> &arr){
    int size = arr.size();

    // finding the max element 
    int max = INT32_MIN;
    for (int i = 0 ; i < size ; i++){
        if (arr[i] > max) max = arr[i];
    }

    // making the freq array
    vector<int> freq(max + 1 , 0);
    for (int i = 0 ; i < size ; i++ ) freq[arr[i]]++;

    // making the cumilative freq array
    for (int i = 0 ; i < max + 1 ; i++) freq[i + 1] += freq[i];

    // making the ans array
    vector<int> ans (size);
    for (int i = size - 1 ; i >= 0 ; i--){
        ans[--freq[arr[i]]] = arr[i];
    }

    // copying back the elements to the given array
    for (int i = 0 ; i < size ; i++) arr[i] = ans[i];

    return;  
}