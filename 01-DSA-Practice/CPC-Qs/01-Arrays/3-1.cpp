#include<bits/stdc++.h>
using namespace std;
bool subArrayExists(int arr[], int n)
    {
        //Your code here
        set<int>s;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0||arr[i]==0) return true;
            else if(s.find(sum)!=s.end()){
                return true;
            }
            else{
                cout << sum << endl;
                s.insert(sum);
            }
                
         }
         return false;
    }
int main()
{
    int arr[4] = {4, 2, -3, 1};
    int a = subArrayExists(arr, 4);
    cout << "ans is " << a;
    return 0;
}