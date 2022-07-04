#include<bits/stdc++.h>
using namespace std;
void solution(vector<vector<int>> a){
    for(int i = 0; i < a.size() - 1; i++){
        if (a[i][1] < a[i+1][0]) {
            continue;
        }
        else{
            a[i][1] = a[i+1][1];
            a[i+1] = {};
        }
    }
}
int main()
{
    
    return 0;
}