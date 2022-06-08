// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Function to find maximum product subarray
long long maxf(long long a, long long b, long long c){
long long max;
 
   if (a >= b && a >= c) {
      max = a;
   }
   else if (b >= a && b >= c) {
      max = b;
   }
   else if (c >= a && c >= b) {
      max = c;
   }
   return max;
}
long long minf(long long a, long long b, long long c){
long long max;
 
   if (a <= b && a <= c) {
      max = a;
   }
   if (b <= a && b <= c) {
      max = b;
   }
   if (c <= a && c <= b) {
      max = c;
   }
   return max;
}
long long maxProduct(vector<int> arr, int n)
{
    if (arr.size() == 1)
    {
        return arr[0];
    }
    // code here
    long result = arr[0];
    long temp = 1;
    for (int i = 0; i < n; i++)
    {
        temp = temp * arr[i];
        if (result < temp)
        {
            result = temp;
        }
        if (temp == 0)
        {
            temp = 1;
        }
    }
    cout << result << endl;
    temp = 1;
    for (int j = n - 1; j > -1; j--)
    {
        temp = temp * arr[j];
        if (result < temp)
        {
            result = temp;
        }
        if (temp == 0)
        {
            temp = 1;
        }
    }
    cout << result << endl;
    return result;
}

// { Driver Code Starts.

int main()
{
    vector<int> vec1 = {6, -3, -10, 0, 2};
    cout << maxProduct(vec1, 5) << endl;
}
