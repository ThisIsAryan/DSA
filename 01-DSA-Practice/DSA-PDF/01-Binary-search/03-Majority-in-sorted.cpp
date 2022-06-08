// Write a C++ function to find if a given integer x appears more than n/2 times in a sorted array of n integers.
// Method 1 is silly, 2 is good, 3 is kinda silly.
// Method 1- 
#include <iostream>
using namespace std;
int findLeftPosition(int A[], int l, int r, int key)
{
    if (A[l] == key)
    {
        return l;
    }
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
    return r;
}
int findRightPosition(int A[], int l, int r, int key)
{
    if (A[r] == key)
    {
        return r;
    }
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
    return l;
}
bool Solution(int A[], int l, int r, int key)
{
    int left = findLeftPosition(A, l, r, key);
    int right = findRightPosition(A, l, r, key);
    if (A[left] == key && A[right] == key)
    {
        bool answer = ((right - left + 1) > ((r - l + 1) / 2)) ? true : false;
        return answer;
    }
    return false;
}

//GFG- 

// Method 2- Use binary search methodology to find the first occurrence of the given number. The criteria for binary search is important here. 
int _binarySearch(int arr[], int low,
                  int high, int x);
 
// This function returns true if the x
// is present more than n/2 times in
// arr[] of size n
bool isMajority(int arr[], int n, int x)
{
     
    // Find the index of first occurrence
    // of x in arr[]
    int i = _binarySearch(arr, 0, n - 1, x);
 
    // If element is not present at all,
    // return false
    if (i == -1)
        return false;
 
    // Check if the element is present
    // more than n/2 times
    if (((i + n / 2) <= (n - 1)) &&
      arr[i + n / 2] == x)
        return true;
    else
        return false;
}
 
// If x is present in arr[low...high] then
// returns the index of first occurrence
// of x, otherwise returns -1
int _binarySearch(int arr[], int low,
                  int high, int x)
{
    if (high >= low)
    {
        int mid = (low + high)/2; /*low + (high - low)/2;*/
 
        /* Check if arr[mid] is the first occurrence of x.
            arr[mid] is first occurrence if x is one of
            the following is true:
            (i) mid == 0 and arr[mid] == x
            (ii) arr[mid-1] < x and arr[mid] == x
        */
        if ((mid == 0 || x > arr[mid - 1]) &&
            (arr[mid] == x) )
            return mid;
             
        else if (x > arr[mid])
            return _binarySearch(arr, (mid + 1),
                                 high, x);
        else
            return _binarySearch(arr, low, 
                                (mid - 1), x);
    }
    return -1;
}

// METHOD 3: If it is already given that the array is sorted and there exists a majority element, i.e., if it is mentioned that there is an element occuring more than size/2 times in the array, checking if a particular element is that majority element is as easy as checking if the middle element of the array is the number we are checking against.

bool isMajorityElement(int arr[], int n, int key)
{
    if (arr[n / 2] == key)
        return true;
    else
        return false;
}

int main()
{
    int arr[] = {1, 2, 5, 5, 5, 5, 5, 5, 6, 7};
    int upperBound = sizeof(arr) / sizeof(arr[0]) - 1;
    cout << "Size- " << upperBound + 1 << endl;
    cout << "Answer- " << Solution(arr, 0, upperBound, 5);
}