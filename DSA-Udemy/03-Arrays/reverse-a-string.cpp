#include <iostream>
#include <string>
using namespace std;
string reverse(string input)
{
    int size = input.length();
    string reverse;
    for (int i = 0; i < size; i++)
    {
        reverse.push_back(input[size - 1 - i]);
    } 
    return reverse;
}
int main()
{
    string str = "Iron Man";
    cout << reverse(str);
    return 0;
}