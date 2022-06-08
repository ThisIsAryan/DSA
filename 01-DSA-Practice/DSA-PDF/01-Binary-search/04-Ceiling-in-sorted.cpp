// Given a sorted array and a value x, the ceiling of x is the smallest element in array greater than or equal to x, and the floor is the greatest element smaller than or equal to x. Assume than the array is sorted in non-decreasing order. Write efficient functions to find floor and ceiling of x.
#include <iostream>
using namespace std;
int findingFloor(int A[], int l, int r, int key)
{
    int m;
    while (r - l > 1)
    {
        m = l + (r - l) / 2;
        if (A[m] <= key)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    return A[l];
}
int findingCeiling(int A[], int l, int r, int key)
{
    int m;
    while (r - l > 1)
    {
        m = l + (r - l) / 2;
        if (A[m] >= key)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    return A[r];
}

//GFG-
/* Function to get index of
   ceiling of x in arr[low..high]*/
int ceilSearch(int arr[], int low, int high, int x)
{
    int mid;    
     
    /* If x is smaller than
       or equal to the first element,
       then return the first element */
    if(x <= arr[low])
        return low;
     
    /* If x is greater than the last element,
       then return -1 */
    if(x > arr[high])
        return -1;
     
    /* get the index of middle element of arr[low..high]*/
    mid = (low + high) / 2; /* low + (high - low)/2 */
     
    /* If x is same as middle element,
       then return mid */
    if(arr[mid] == x)
        return mid;
         
    /* If x is greater than arr[mid],
       then either arr[mid + 1] is ceiling of x
       or ceiling lies in arr[mid+1...high] */
    else if(x > arr[mid])
    {
        if(mid + 1 <= high && x <= arr[mid + 1])
            return mid + 1;
        else
            return ceilSearch(arr, mid + 1, high, x);
    }
     
    /* If x is smaller than arr[mid],
       then either arr[mid] is ceiling of x
       or ceiling lies in arr[low...mid-1] */
    else
    {
        if(mid - 1 >= low && x > arr[mid - 1])
            return mid;
        else
            return ceilSearch(arr, low, mid - 1, x);
    }
}
 
int main()
{
    int arr[] = {1, 2, 3, 4, 6, 7, 8, 9};
    int upperBound = sizeof(arr)/sizeof(arr[0]) - 1;
    cout << findingFloor(arr, 0, upperBound, 5) << " " << findingCeiling(arr, 0, upperBound, 5);
    return 0;
}