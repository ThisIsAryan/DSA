#include <iostream>
using namespace std;

string LongestWord(string sen)
{

    // code goes here
    string longestWord;
    string currentWord;
    for (string::size_type i = 0; i < sen.length(); ++i)
    {
        currentWord.clear();

        while (i < sen.length())
        {
            if ((sen[i] >= 65 && sen[i] <= 90) || (sen[i] >= 97 && sen[i] <= 122))
                currentWord += sen[i++];
            else
                break;
        }
        if (longestWord.length() < currentWord.length())
            longestWord = currentWord;
    }
    
    return longestWord;
}

int main()
{

    // keep this function call here
    cout << LongestWord("I like big butts and I can not lie");
    return 0;
}