//Reverse an array-
#include<iostream>
using namespace std;
string reverseWord(string str){
    int size = str.length();
    char temp;
    cout << size << " " << str << endl;
    for(int i = 0; i < size/2; i++){
        temp = str[i];
        str[i] = str[size-1-i];
        str[size-1-i] = temp;
    }
    cout << str << endl;
    return str;
  //Your code here
}
int main()
{
    string str = "Sukhi Proxy";
    cout << reverseWord(str) << endl;
    cout << str << endl;
    return 0;
}

void rvereseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rvereseArray(int arr[], int start, int end)
{
    if (start >= end)
    return;
     
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
     
    // Recursive Function calling
    rvereseArray(arr, start + 1, end - 1);
} 