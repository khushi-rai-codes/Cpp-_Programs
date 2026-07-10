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
    void display()
    {
        cout << "\n----- Student Details -----\n";
        cout << "Roll Number : " << roll << endl;
        cout << "Name        : " << name << endl;
        cout << "Marks       : " << marks << endl;
    }
};
int main()
{
    Student s;
    s.input();
    s.display();
    return 0;
}
