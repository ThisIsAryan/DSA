#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)
    {
        // code here
        set<int> s1;
        for (int i = 0; i < n; i++)
        {
            s1.insert(a[i]);
        }
        for (int i = 0; i < m; i++)
        {
            s1.insert(b[i]);
        }
        return s1.size();
    }
};
int main()
{
    return 0;
}