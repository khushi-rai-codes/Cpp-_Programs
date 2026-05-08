#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    char temp;
    cout << "Enter a string: ";
    getline(cin, str);
    for(int i = 0; i < str.length() - 1; i++)
    {
        for(int j = i + 1; j < str.length(); j++)
        {
            if(str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    cout << "Sorted string: " << str;
    return 0;
}
