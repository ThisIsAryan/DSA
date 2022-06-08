//Q1- Given a sorted array of N distinct elements. Find a key in the array using least number of comparisons.
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

// The following implementation uses fewer number of comparisons - USE THIS!!
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
}//In the while loop we are depending only on one comparison.

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

//Q2- Given an array of N distinct integers, find floor value of input ‘key’.
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
    if (key > A[r]) //important to keep this check.
        return A[r];
    else
    {
        int m;
        while (r - l > 1) //not while(l <= r) or while(r - l >= 1) , as it can create an infinite loop.
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
} //O(log(n))

//Q3- Given a sorted array with possible duplicate elements. Find number of occurrences of input ‘key’ in log N time.
int GetRightPosition(int A[], int l, int r, int key)
{
    if (A[r] <= key)
        return r;
    int m;
    while (r - l > 1)
    {
        m = l + (r - l) / 2;

        if (A[m] <= key)
            l = m;
        else
            r = m;
    }

    return l;
}
int GetLeftPosition(int A[], int l, int r, int key)
{
    if (A[l] >= key)
        return l;
    int m;
    while (r - l > 1)
    {
        m = l + (r - l) / 2;

        if (A[m] >= key)
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
    return (A[left] == key && key == A[right]) ? (right - left + 1) : 0;
}

//Q4- Given a sorted array of distinct elements, and the array is rotated at an unknown position. Find minimum element in the array. eg.{8, 13, 16, 19, 3, 4, 5, 7} - 3.
//Here, the leftmost element has to be the largest element.
int findingInversionPoint(int A[], int l, int r)
{
    if(A[l] <= A[r])
    return l; //no rotation.
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
    return m; //not l
}
int SortedMinimumBinary(int A[], int l, int r)
{
    int i = findingInversionPoint(A, l, r);
    if (A[l] <= A[i])
    {
        return A[l];
    }
    else
    {
        return A[i];
    }
}
//Another approach-
int BinarySearchIndexOfMinimumRotatedArray(int A[], int l, int r)
{
    // extreme condition, size zero or size two
    int m;
    // Precondition: A[l] > A[r]
    if (A[l] <= A[r])
        return l;
    while (l <= r)
    {
        // Termination condition (l will eventually falls on r, and r always point minimum possible value)
        if (l == r)
            return A[l];
        m = l + (r - l) / 2; // 'm' can fall in first pulse, second pulse or exactly in the middle
        if (A[m] < A[r])
            // min can't be in the range (m < i <= r), we can exclude A[m+1 ... r]
            r = m;
        else
            // min must be in the range (m < i <= r), we must search in A[m+1 ... r]
            l = m + 1;
    }
    return -1;
}

//O(n)-
bool OnArray(int a[], int l, int r, int key){
    if(r<l)
    return false;
    int m;
    while(r-l>1){
        m = l + (r-l)/2;
        if(a[m] < key){
            l = m;
        }
        else{
            r = m + 1;
        }
    }
    if(a[l] == key){
        return true;
    }
    else if(a[r]  == key){
        return true;
    }
    return false;
}



int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 8};
    int upperBound = sizeof(arr) / sizeof(arr[0]) - 1;
    cout << OnArray(arr, 0, upperBound, 4) << endl;
    cout << upperBound << " " << BinarySearch(arr, 0, upperBound, 8) << " " << BinarySearch2(arr, 0, upperBound, 4)
         << " " << binarySearch3(arr, 0, upperBound, 5) << endl; //6 6 3 4

    cout << floorValue(arr, 0, upperBound, 7) << " " << floorValueBinary(arr, 0, upperBound, 10) << endl;

    int arr2[] = {1, 2, 3, 4, 5, 5, 6, 6, 6, 7};
    int upperBound2 = sizeof(arr2) / sizeof(arr2[0]) - 1;
    cout << countOccurances2(arr2, upperBound2, 6) << endl;

    int arr3[] = {8, 13, 16, 19, 3, 4, 5, 7};
    int upperBound3 = sizeof(arr3) / sizeof(arr3[0]) - 1;
    cout << SortedMinimumBinary(arr3, 0, upperBound3) << " " << BinarySearchIndexOfMinimumRotatedArray(arr3, 0, upperBound3);

    return 0;
}