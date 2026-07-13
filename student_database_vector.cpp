#include <iostream>
#include <vector>
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
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    vector<Student> students(n);
    for(int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Roll: ";
        cin >> students[i].roll;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Marks: ";
        cin >> students[i].marks;
    }
    cout << "\nStudent Records\n";
    for(const auto &s : students)
    {
        cout << "\nRoll : " << s.roll;
        cout << "\nName : " << s.name;
        cout << "\nMarks: " << s.marks << endl;
    }
    return 0;
}
