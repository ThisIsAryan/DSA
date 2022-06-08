#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        int MaxSum = arr[0], CurrSum = 0;
        for(int i = 0; i < n; i++){
            CurrSum += arr[i];
            MaxSum = max(CurrSum, MaxSum);
            if(CurrSum < 0){
                CurrSum = 0;
            }
        }
        return MaxSum;
    }
};
int main()
{
    
    return 0;
}