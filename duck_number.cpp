#include<iostream>
using namespace std;
int main()
{
    int num, temp;
    bool isDuck = false;
    cout << "Enter a number: ";
    cin >> num;
    temp = num;
    while(temp > 0)
    {
        if(temp % 10 == 0)
        {
            isDuck = true;
            break;
        }
        temp = temp / 10;
    }
    if(isDuck)
        cout << num << " is a Duck Number";
    else
        cout << num << " is not a Duck Number";
    return 0;
}
