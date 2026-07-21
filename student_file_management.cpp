#include <iostream>
#include <fstream>
using namespace std;
class Student
{
public:
    int roll;
    string name;
    float marks;
};
int main()
{
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.roll;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Marks: ";
    cin >> s.marks;
    ofstream file("students.txt", ios::app);
    file << s.roll << " "
         << s.name << " "
         << s.marks << endl;
    file.close();
    cout << "Student record saved successfully.";
    return 0;
}
