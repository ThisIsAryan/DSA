#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[42];
    for(int i = 0; i< 42; i++){
        cin >> arr[i];
    }
    sort(arr,arr+42);
    for(int i : arr){
        cout << i << "  ";
    }
    return 0;
}