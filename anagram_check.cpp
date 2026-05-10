#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str1, str2;
    int freq[256] = {0};
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    if(str1.length() != str2.length())
    {
        cout << "Not Anagrams";
        return 0;
    }
    for(char ch : str1)
        freq[(int)ch]++;
    for(char ch : str2)
        freq[(int)ch]--;
    for(int i = 0; i < 256; i++)
    {
        if(freq[i] != 0)
        {
            cout << "Not Anagrams";
            return 0;
        }
    }
    cout << "Anagrams";
    return 0;
}
