#include<iostream>
using namespace std;
int main()
{
    int units;
    float bill;
    cout << "Enter electricity units consumed: ";
    cin >> units;
    if(units <= 100)
    {
        bill = units * 1.5;
    }
    else if(units <= 300)
    {
        bill = (100 * 1.5) + ((units - 100) * 2.5);
    }
    else
    {
        bill = (100 * 1.5) + (200 * 2.5) + ((units - 300) * 4);
    }
    cout << "Total Electricity Bill = " << bill;
    return 0;
}
