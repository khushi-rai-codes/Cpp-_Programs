#include<iostream>
using namespace std;
struct Student
{
    int roll;
    string name;
};
Student students[100];
int countStudents = 0;
void addStudent()
{
    cout << "Enter Roll Number: ";
    cin >> students[countStudents].roll;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, students[countStudents].name);
    countStudents++;
    cout << "Student Added Successfully\n";
}
void displayStudents()
{
    for(int i = 0; i < countStudents; i++)
    {
        cout << "\nRoll: " << students[i].roll;
        cout << "\nName: " << students[i].name << endl;
    }
}
void searchStudent()
{
    int roll;
    cout << "Enter Roll Number: ";
    cin >> roll;
    for(int i = 0; i < countStudents; i++)
    {
        if(students[i].roll == roll)
        {
            cout << "Student Found\n";
            cout << students[i].name << endl;
            return;
        }
    }
    cout << "Student Not Found\n";
}
int main()
{
    int choice;
    do
    {
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
        }
    } while(choice != 4);
    return 0;
}
