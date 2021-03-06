// Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] such that sorting this subarray makes the whole array sorted.
// Examples:
// 1) If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], your program should be able to find that the subarray lies between the indexes 3 and 8.
// 2) If the input array is [0, 1, 15, 25, 6, 7, 30, 40, 50], your program should be able to find that the subarray lies between the indexes 2 and 5.
#include <iostream>
using namespace std;
void solution(int arr[], int size)
{
    int s, e;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            s = i;
            break;
        }
    }
    for (int i = size - 1; i > 0; i--)
    {
        if (arr[i - 1] > arr[i])
        {
            e = i;
            break;
        }
    }
    cout << size << " " << s << " " << e << endl;
    int min = arr[s], max = arr[e];
    for (int i = s; i < e; i++)
    {
        if (arr[i] < arr[s])
        {
            min = arr[i];
        }
        if (arr[i] > arr[e])
        {
            max = arr[i];
        }
    }
    for (int i = 0; i < s; i++)



    {
        if (arr[i] > min)
        {
            s = i;
            break;
        }
    }
    for (int i = size - 1; i > e; i--)
    {
        if (arr[i] < max)
        {
            e = i;
            break;
        }
    }
    cout << s << " " << e;
    return;
}
// Solution: https://www.youtube.com/watch?v=UfBfr-VRYOU
// 1) Find the candidate unsorted subarray
// a) Scan from left to right and find the first element which is greater than the next element. Let s be the index of such an element. In the above example 1, s is 3 (index of 30).
// b) Scan from right to left and find the first element (first in right to left order) which is smaller than the next element (next in right to left order). Let e be the index of such an element. In the above example 1, e is 7 (index of 31).
// 2) Check whether sorting the candidate unsorted subarray makes the complete array sorted or not. If not, then include more elements in the subarray.
// a) Find the minimum and maximum values in arr[s..e]. Let minimum and maximum values be min and max. min and max for [30, 25, 40, 32, 31] are 25 and 40 respectively.
// b) Find the first element (if there is any) in arr[0..s-1] which is greater than min, change s to index of this element. There is no such element in above example 1.
// c) Find the last element (if there is any) in arr[e+1..n-1] which is smaller than max, change e to index of this element. In the above example 1, e is changed to 8 (index of 35)
// 3) Print s and e
void printUnsorted(int arr[], int n)
{
    int s = 0, e = n - 1, i, max, min;

    // step 1(a) of above algo
    for (s = 0; s < n - 1; s++)
    {
        if (arr[s] > arr[s + 1])
            break;
    }
    if (s == n - 1)
    {
        cout << "The complete array is sorted";
        return;
    }

    // step 1(b) of above algo
    for (e = n - 1; e > 0; e--)
    {
        if (arr[e] < arr[e - 1])
            break;
    }

    // step 2(a) of above algo
    max = arr[s];
    min = arr[s];
    for (i = s + 1; i <= e; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    // step 2(b) of above algo
    for (i = 0; i < s; i++)
    {
        if (arr[i] > min)
        {
            s = i;
            break;
        }
    }

    // step 2(c) of above algo
    for (i = n - 1; i >= e + 1; i--)
    {
        if (arr[i] < max)
        {
            e = i;
            break;
        }
    }

    // step 3 of above algo
    cout << "The unsorted subarray which"
         << " makes the given array" << endl
         << "sorted lies between the indees "
         << s << " and " << e << endl;
    return;
}
//Note- no need to sort the array.
int main()
{
    int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    printUnsorted(arr, size); // 3 and 8
    int arr2[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    solution(arr2, size2); //2 and 8
    return 0;
}