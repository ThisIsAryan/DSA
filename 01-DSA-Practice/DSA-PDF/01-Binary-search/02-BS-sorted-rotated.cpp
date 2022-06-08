// Search an element in a sorted and rotated array
// {6, 7 ,8, 9, 10, 1, 2, 3, 4, 5} //O(log(n))
#include <iostream>
using namespace std;
int BinarySearch(int A[], int l, int r, int key)
{
    //initial checks;
    int m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (A[m] == key)
        {
            return m;
        }
        if (A[m] < key)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}
int FindingInversionPoint(int A[], int l, int r)
{
    //initial checks.
    if (A[l] <= A[r])
    {
        return l;
    }
    int m;
    while (r - l > 1)
    {
        m = l + (r - l) / 2;
        if (A[l] < A[m])
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    return m;
}
int FindingElement(int A[], int l, int r, int key)
{
    int p = FindingInversionPoint(A, l, r);
    if (A[p] == key)
    {
        return p;
    }
    if (A[0] <= key)
    {
        return BinarySearch(A, l, p - 1, key);
    }
    else
        return BinarySearch(A, p, r, key);
}

//GFG-
/* Standard Binary Search function*/
int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
    // else
    return binarySearch(arr, low, (mid - 1), key);
}
/* Function to get pivot. For array 3, 4, 5, 6, 1, 2 it returns 3 (index of 6) */
int findPivot(int arr[], int low, int high)
{
    // base cases
    if (high < low)
        return -1;
    if (high == low)
        return low;

    int mid = (low + high) / 2; /*low + (high - low)/2;*/
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;

    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);

    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);

    return findPivot(arr, mid + 1, high);
}
/* Searches an element key in a pivoted
   sorted array arr[] of size n */
int pivotedBinarySearch(int arr[], int n, int key)
{
    int pivot = findPivot(arr, 0, n - 1);

    // If we didn't find a pivot,
    // then array is not rotated at all
    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);

    // If we found a pivot, then first compare with pivot
    // and then search in two subarrays around pivot
    if (arr[pivot] == key)
        return pivot;

    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);

    return binarySearch(arr, pivot + 1, n - 1, key);
}

//Another approach-
// Search an element in sorted and rotated array using single pass of Binary Search Returns index of key in arr[l..h] if key is present, otherwise returns -1
int search(int arr[], int l, int h, int key)
{
    if (l > h)
        return -1;
    int mid = (l + h) / 2;
    if (arr[mid] == key)
        return mid;
    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid])
    {
        /* As this subarray is sorted, we can quickly
        check if key lies in half or other half */
        if (key >= arr[l] && key <= arr[mid])
            return search(arr, l, mid - 1, key);
        /*If key not lies in first half subarray,
           Divide other half  into two subarrays,
           such that we can quickly check if key lies
           in other half */
        return search(arr, mid + 1, h, key);
    }

    /* If arr[l..mid] first subarray is not sorted, then arr[mid... h]
    must be sorted subarray */
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid + 1, h, key);

    return search(arr, l, mid - 1, key);
}

int main()
{
    int arr[] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    int upperBound = sizeof(arr) / sizeof(arr[0]) - 1;
    cout << FindingElement(arr, 0, upperBound, 3);
    return 0;
}
