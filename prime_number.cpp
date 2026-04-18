#include<iostream>
using namespace std;
int main()
{
    int n, flag = 0;
    cout << "Enter a number: ";
    cin >> n;
    if(n <= 1)
    {
        cout << "Not a prime number";
    }
    else
    {
        for(int i = 2; i <= n/2; i++)
        {
            if(n % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            cout << "Prime number";
        else
            cout << "Not a prime number";
    }
    return 0;
}
