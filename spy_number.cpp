#include<iostream>
using namespace std;
int main()
{
    int num, digit, sum = 0, product = 1;
    cout << "Enter a number: ";
    cin >> num;
    int temp = num;
    while(temp > 0)
    {
        digit = temp % 10;
        sum += digit;
        product *= digit;
        temp = temp / 10;
    }
    if(sum == product)
        cout << num << " is a Spy Number";
    else
        cout << num << " is not a Spy Number";
    return 0;
}
