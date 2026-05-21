#include<iostream>
using namespace std;
int main()
{
    int num, square, sum = 0, digit;
    cout << "Enter a number: ";
    cin >> num;
    square = num * num;
    while(square > 0)
    {
        digit = square % 10;
        sum += digit;
        square = square / 10;
    }
    if(sum == num)
        cout << num << " is a Neon Number";
    else
        cout << num << " is not a Neon Number";
    return 0;
}
