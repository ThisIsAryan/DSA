//Given a sorted array of N distinct elements. Find a key in the array using least number of comparisons.
#include <iostream>
using namespace std;
int BinarySearch(int A[], int l, int r, int key)
{
    int m;

    while (l <= r)
    {
        m = l + (r - l) / 2;

        if (A[m] == key) // first comparison
            return m;

        if (A[m] < key) // second comparison
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

//Theoretically we need log N + 1 comparisons in worst case. If we observe, we are using two comparisons per iteration except
// during final successful match, if any. In practice, comparison would be costly operation, it won’t be just primitive type
// comparison. It is more economical to minimize comparisons as that of theoretical limit.

// The following implementation uses fewer number of comparisons.

// Invariant: A[l] <= key and A[r] > key
// Boundary: |r - l| = 1
// Input: A[l .... r-1]
int BinarySearch2(int A[], int l, int r, int key)
{
    int m;

    while (r - l > 1)
    {
        m = l + (r - l) / 2;

        if (A[m] <= key)
            l = m;
        else
            r = m;
    }

    if (A[l] == key)
        return l;
    if (A[r] == key)
        return r;
    else
        return -1;
}
//In the while loop we are depending only on one comparison.

//recursively-
int binarySearch3(int A[], int l, int r, int key)
{
    int m = l + (r - l) / 2;
    if (A[m] == key)
    {
        return m;
    }
    else if (A[m] < key)
    {
        return binarySearch3(A, m + 1, r, key);
    }
    else
    {
        return binarySearch3(A, l, m - 1, key);
    }
    return -1;
}

//Problem Statement: Given an array of N distinct integers, find floor value of input ‘key’.
// Say, A = {-1, 2, 3, 5, 6, 8, 9, 10} and key = 7, we should return 6 as outcome.

int floorValue(int A[], int l, int r, int key)
{
    int i;
    for (i = l; i < r; i++)
    {
        if (A[i] <= key)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return A[i - 1];
} //O(n)

int floorValueBinary(int A[], int l, int r, int key)
{
    // Add error checking if key < A[0]
    if (key < A[0])
        return -1;
    else
    {
        int m;
        while (r - l > 1) //not while(l <= r)
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
}

//Given a sorted array with possible duplicate elements. Find number of occurrences of input ‘key’ in log N time.
int countOccurances(int A[], int l, int r, int key)
{
    int count = 0;
    while(l <= r){
    int m = l + (r - l) / 2;
    if (A[m] == key){
        count++;
        l = m + 1; //not l = l + 1;
    }
    else if(A[m] < key){
        l = m + 1;
    }
    else{
        r = m - 1;
    }
    }
    return count;
}

//another approach- 


// Input: Indices Range [l ... r)
// Invariant: A[l] <= key and A[r] > key
int GetRightPosition(int A[], int l, int r, int key)
{
    int m;
  
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
  
        if( A[m] <= key )
            l = m;
        else
            r = m;
    }
  
    return l;
}
// Input: Indices Range (l ... r]
// Invariant: A[r] >= key and A[l] > key
int GetLeftPosition(int A[], int l, int r, int key)
{
    int m;
  
    while( r - l > 1 )
    {
        m = l + (r - l)/2;
  
        if( A[m] >= key )
            r = m;
        else
            l = m;
    }
  
    return r;
}
  
int countOccurances2(int A[], int size, int key)
{
    // Observe boundary conditions
    int left = GetLeftPosition(A, 0, size, key);
    int right = GetRightPosition(A, 0, size, key);
  
    // What if the element doesn't exists in the array?
    // The checks helps to trace that element exists
    return (A[left] == key && key == A[right])?
           (right - left + 1) : 0;
}

//Problem Statement: Given a sorted array of distinct elements, 
// and the array is rotated at an unknown position. Find minimum element in the array.


int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 8};
    int upperBound = sizeof(arr) / sizeof(arr[0]) - 1;
    cout << upperBound << " " << BinarySearch(arr, 0, upperBound, 8) << " " << BinarySearch2(arr, 0, upperBound, 4)
         << " " << binarySearch3(arr, 0, upperBound, 5) << endl;

    cout << floorValue(arr, 0, upperBound, 7) << " " << floorValueBinary(arr, 0, upperBound, 7) << endl;

    int arr2[] = {1, 2, 3, 4, 5, 5, 6, 6, 7};
    int upperBound2 = sizeof(arr2) / sizeof(arr2[0]) - 1;
    cout << countOccurances(arr2, 0, upperBound2, 5) << " " << countOccurances2(arr2, upperBound2, 5) << endl;

    return 0;
}