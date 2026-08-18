#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Student
{
    string name;
    double marks;
};
int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    vector<Student> students(n);
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Enter Name: ";
        cin >> students[i].name;
        cout << "Enter Marks: ";
        cin >> students[i].marks;
    }
    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b)
         {
             return a.marks > b.marks;
         });
    cout << "\n===== Student Ranking =====\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Rank " << i + 1
             << " - " << students[i].name
             << " : " << students[i].marks
             << endl;
    }
    return 0;
}
