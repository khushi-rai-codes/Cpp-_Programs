#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    int num = 1;
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 == 1)
        {
            for(int j = 1; j <= i; j++)
                cout << num++ << " ";
        }
        else
        {
            int start = num + i - 1;

            for(int j = start; j >= num; j--)
                cout << j << " ";
            num += i;
        }
        cout << endl;
    }
    return 0;
}
