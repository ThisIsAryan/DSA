//Check whether 2 arrays have the same element.

#include<iostream>
#include<cstring>
//#include<vector>
using namespace std;
//bool findName(vector<string> a1, vector<string> a2)
bool findName(string a1[], string a2[])
{
    int check = 0;
    for(int i = 0; i < a1->length(); i++)
    for(int j = 0; j < a2->length(); j++)
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
    string arr1[] = {"main", "not", "python"};
    string arr2[] = {"cool", "dude", "space", "not"};
    //vector<string> arr1 = {"main", "not", "python"};
    //vector<string> arr2 = {"cool", "dude", "space", "not"};
    int c = findName(arr1, arr2);
    if(c==1){
        cout<<"Found a match";
    }
    else
    cout<<"No Match";
    return 0;
}

