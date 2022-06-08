//Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]. Expected time complexity is O(Logn)
// eg. Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 2
//     Output: 4 // x (or 2) occurs 4 times in arr[]

#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
    if (r < 1)
        return -1;
    int mid = l + (r - l) / 2;
    //if in middle-
    if (arr[mid] == x)
        return mid;
    // If element is smaller than mid, then it can only be present in left subarray
    if (arr[mid] > x)
    {
        return binarySearch(arr, l, mid - 1, x);
    }
    return binarySearch(arr, mid + 1, r, x);
}
int countOccurrences(int arr[], int n, int x)
{
    int ind = binarySearch(arr, 0, n - 1, x);
    //if element not present-
    if (ind == -1)
        return 0;
    //count elements to the left-
    int count = 1;
    int left = ind - 1;
    while (left >= 0 && arr[left] == x)
        count++, left--;
    //count elements to the right-
    int right = ind + 1;
    while (right < n && arr[right] == x)
        count++, right++;
    return count;
}
//Best using Binary Search-

//1) Use Binary search to get index of the first occurrence of x in arr[]. Let the index of the first occurrence be i.
//2) Use Binary search to get index of the last occurrence of x in arr[]. Let the index of the last occurrence be j.
//3) Return (j – i + 1);

/* if x is present in arr[] then returns the count
    of occurrences of x, otherwise returns 0. */
int count(int arr[], int x, int n)
{   
  /* get the index of first occurrence of x */
  int *low = lower_bound(arr, arr+n, x);
 
  // If element is not present, return 0
  if (low == (arr + n) || *low != x)
     return 0;
    
  /* Else get the index of last occurrence of x.
     Note that we  are only looking in the
     subarray after first occurrence */  
  int *high = upper_bound(low, arr+n, x);    
  cout << "check" << " " << high << " " << *high;
  cout << "check" << " " << low << " " << *low;
    
  /* return count */
  return high - low;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    cout << countOccurrences(arr, n, x) << endl;
    cout << count(arr, x, n);
    return 0;
}