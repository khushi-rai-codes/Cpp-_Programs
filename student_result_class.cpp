#include <iostream>
using namespace std;
class Student
{
private:
    int roll;
    string name;
    float marks;
public:
    void input()
    {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }
    void result()
    {
        cout << "\nStudent Details\n";
        cout << "Roll Number : " << roll << endl;
        cout << "Name        : " << name << endl;
        cout << "Marks       : " << marks << endl;
        if (marks >= 40)
            cout << "Result      : Pass";
        else
            cout << "Result      : Fail";
    }
};
int main()
{
    Student s;
    s.input();
    s.result();
    return 0;
}
