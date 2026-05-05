#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str, result = "";
    cout << "Enter a string: ";
    getline(cin, str);
    for(char ch : str)
    {
        if(ch != ' ')
        {
            result += ch;
        }
    }
    cout << "String without spaces: " << result;
    return 0;
}
