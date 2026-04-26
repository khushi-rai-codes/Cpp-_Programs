#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int num, original, remainder;
    int result = 0;
    cout << "Enter a number: ";
    cin >> num;
    original = num;
    while(num != 0)
    {
        remainder = num % 10;
        result = result + pow(remainder, 3);
        num = num / 10;
    }
    if(original == result)
        cout << "Armstrong number";
    else
        cout << "Not an Armstrong number";
    return 0;
}
