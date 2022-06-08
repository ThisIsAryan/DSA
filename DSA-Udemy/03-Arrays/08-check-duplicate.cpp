#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
        map<int, bool> solution;
        for(int i = 0; i < nums.size(); i++){
            if(solution[nums[i]]){
                return true;
            }
            solution[nums[i]] = true;
            }
        return false;
}

int main(){
    vector<int> ar = {1, 3, 5, 8, 9, 3};
    cout<<containsDuplicate(ar);
}