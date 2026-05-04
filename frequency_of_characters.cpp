#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    int freq[256] = {0}
    cout << "Enter a string: ";
    getline(cin, str);
    for(char ch : str)
    {
        if(ch != ' ')
        {
            freq[(int)ch]++;
        }
    }
    cout << "Character frequencies:\n";
    for(int i = 0; i < 256; i++)
    {
        if(freq[i] > 0)
        {
            cout << (char)i << " = " << freq[i] << endl;
        }
    }
    return 0;
}
