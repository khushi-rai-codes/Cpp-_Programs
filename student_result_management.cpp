#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class Student
{
private:
    int rollNo;
    string name;
    float marks;
public:
    void input()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }
    void display() const
    {
        cout << left << setw(10) << rollNo
             << setw(20) << name
             << setw(10) << marks;
        if (marks >= 40)
            cout << "Pass";
        else
            cout << "Fail";
        cout << endl;
    }
};
int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    vector<Student> students(n);
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Student " << i + 1 << endl;
        students[i].input();
    }
    cout << "\n---------------------------------------------\n";
    cout << left << setw(10) << "Roll"
         << setw(20) << "Name"
         << setw(10) << "Marks"
         << "Result" << endl;
    cout << "---------------------------------------------\n";
    for (const Student &s : students)
        s.display();
    return 0;
}
