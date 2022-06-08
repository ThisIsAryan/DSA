//Maximum and minimum of an array using minimum number of comparisons
#include <iostream>
using namespace std;

int min(int arr[], int size){
    int minVal = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] < minVal){
            minVal = arr[i];
        }
    }
    return minVal;
}

int max(int arr[], int size){
    int maxVal = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] > maxVal){
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    int arr[] = {4, 6, 2, 8, 1, 8, 3, -2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << min(arr, size) << endl << max(arr, size) << endl;
	cout<<"GfG!";
	return 0;
}