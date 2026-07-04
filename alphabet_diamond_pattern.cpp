#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n - 1; j++)
            cout << " ";
        for(char ch = 'A'; ch <= 'A' + i; ch++)
            cout << ch;
        for(char ch = 'A' + i - 1; ch >= 'A'; ch--)
            cout << ch;
        cout << endl;
    }
    for(int i = n - 2; i >= 0; i--)
    {
        for(int j = n - 1; j > i; j--)
            cout << " ";
        for(char ch = 'A'; ch <= 'A' + i; ch++)
            cout << ch;
        for(char ch = 'A' + i - 1; ch >= 'A'; ch--)
            cout << ch;
        cout << endl;
    }
    return 0;
}
