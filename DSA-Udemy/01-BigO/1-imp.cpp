//Check whether 2 arrays have the same element.

#include<iostream>
#include<cstring>
//#include<vector>
using namespace std;
//bool findName(vector<string> a1, vector<string> a2)
bool findName(string a1[], string a2[], int size1, int size2)
{
    int check = 0;
    for(int i = 0; i < size1; i++)
    for(int j = 0; j < size2; j++)
    {
        if(a1[i] == a2[j])
        {
            check = 1;
        }
    }
    if(check==1){
        return true;
    }
    else
    return false;
}
int main()
{
    string arr1[] = {"match", "not", "python"};
    string arr2[] = {"catch", "dude", "space", "not"};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    //vector<string> arr1 = {"main", "not", "python"};
    //vector<string> arr2 = {"cool", "dude", "space", "not"};
    int c = findName(arr1, arr2, size1, size2);
    if(c==1){
        cout<<"Found a match";
    }
    else
    cout<<"No Match";
    return 0;
}

