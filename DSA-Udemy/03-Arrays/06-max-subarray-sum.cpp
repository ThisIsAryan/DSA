#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int CurrentSum = nums[0];
        int sum;
        int position = 0;
        for( ; position < nums.size() ; position ++ ){
            sum += nums[position];
            if(CurrentSum <= sum){
                CurrentSum = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return CurrentSum;
    }
};
int main()
{
    
    return 0;
}
//[-2,1,-3,4,-1,2,1,-5,4]
//CurrentSum- 0
//sum- 1