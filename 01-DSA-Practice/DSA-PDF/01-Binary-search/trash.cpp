#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3};
    //vector<int>::iterator itr = v.begin();
    int * p = v.begin();
    cout << p << endl;
    return 0;
}
