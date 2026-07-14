#include <iostream>
using namespace std;
int main()
{
    float principal, rate, time, interest;
    cout << "Enter Principal Amount: ";
    cin >> principal;
    cout << "Enter Rate of Interest: ";
    cin >> rate;
    cout << "Enter Time (Years): ";
    cin >> time;
    interest = (principal * rate * time) / 100;
    cout << "Simple Interest = " << interest << endl;
    cout << "Total Amount = " << principal + interest;
    return 0;
}
