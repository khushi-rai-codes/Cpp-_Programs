#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    for(int i = n; i >= 1; i--)
    {
        for(int j = 0; j < n - i; j++)
            cout << " ";
        for(char ch = 'A'; ch < 'A' + i; ch++)
            cout << ch;
        cout << endl;
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j < n - i; j++)
            cout << " ";
        for(char ch = 'A'; ch < 'A' + i; ch++)
            cout << ch;
        cout << endl;
    }
    return 0;
}
