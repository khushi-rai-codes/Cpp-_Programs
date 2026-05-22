#include<iostream>
using namespace std;
int main()
{
    int num, square, temp, digits = 0;
    cout << "Enter a number: ";
    cin >> num;
    square = num * num;
    temp = num;
    while(temp > 0)
    {
        digits++;
        temp = temp / 10;
    }
    int divisor = 1;
    for(int i = 0; i < digits; i++)
    {
        divisor *= 10;
    }
    if(square % divisor == num)
        cout << num << " is an Automorphic Number";
    else
        cout << num << " is not an Automorphic Number";
    return 0;
}
