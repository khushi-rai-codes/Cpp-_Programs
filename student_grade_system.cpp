#include<iostream>
using namespace std;
int main()
{
    float marks, percentage;
    cout << "Enter marks out of 100: ";
    cin >> marks;
    percentage = marks;
    cout << "Percentage = " << percentage << endl;
    if(percentage >= 90)
        cout << "Grade A";
    else if(percentage >= 75)
        cout << "Grade B";
    else if(percentage >= 60)
        cout << "Grade C";
    else if(percentage >= 40)
        cout << "Grade D";
    else
        cout << "Fail";
    return 0;
}
