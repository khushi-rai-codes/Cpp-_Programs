#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int binary, decimal = 0, base = 0, remainder;
    cout << "Enter a binary number: ";
    cin >> binary;
    while(binary > 0)
    {
        remainder = binary % 10;
        decimal += remainder * pow(2, base);
        binary = binary / 10;
        base++;
    }
    cout << "Decimal = " << decimal;
    return 0;
}
