#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    int count = 0;
    cout << "Enter a sentence: ";
    getline(cin, str);
    for(int i = 0; i < str.length(); i++)
    {
        if((i == 0 && str[i] != ' ') ||
           (str[i] == ' ' && i + 1 < str.length() && str[i + 1] != ' '))
        {
            count++;
        }
    }
    cout << "Number of words = " << count;
    return 0;
}
