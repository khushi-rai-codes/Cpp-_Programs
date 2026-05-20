#include<iostream>
using namespace std;
int main()
{
    int num, octal[32], i = 0;
    cout << "Enter a decimal number: ";
    cin >> num;
    if(num == 0)
    {
        cout << "Octal = 0";
        return 0;
    }
    while(num > 0)
    {
        octal[i] = num % 8;
        num = num / 8;
        i++;
    }
    cout << "Octal = ";
    for(int j = i - 1; j >= 0; j--)
    {
        cout << octal[j];
    }
    return 0;
}
