#include <iostream>
#include <string>
// 345 -> 5 4 3 -> 3+4+5
using namespace std;
string sumOfDigit(string input)
{
    string result;
    int sum = 0;
    int end = input.size();
    for (int i = 0; i < end + 1; i++)
    {
        if (input[i] == ' ' || input[i] == '\0')
        {
            if (sum / 10 == 0)
            {
                result += to_string(sum);
            }
            else
            {
                result += to_string(sum / 10); //as highest sum will be less than 100 only
                result += to_string(sum % 10);
            }
            result = result + " ";
            sum = 0;
        }
        else
        {
            sum += input[i] - '0';
        }
    }
    return result;
}

int main()
{
    string input = "123 456 710";
    cout << "Go- ";
    //getline(cin, input);
    cout << sumOfDigit(input);
    return 0;
}