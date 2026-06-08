#include<iostream>
using namespace std;
struct Course
{
    int id;
    string name;
};
Course courses[100];
int countCourses = 0;
void addCourse()
{
    cout << "Enter Course ID: ";
    cin >> courses[countCourses].id;
    cin.ignore();
    cout << "Enter Course Name: ";
    getline(cin, courses[countCourses].name);
    countCourses++;
    cout << "Course Added Successfully\n";
}
void displayCourses()
{
    for(int i = 0; i < countCourses; i++)
    {
        cout << "\nID: " << courses[i].id;
        cout << "\nName: " << courses[i].name << endl;
    }
}
void searchCourse()
{
    int id;
    cout << "Enter Course ID: ";
    cin >> id;
    for(int i = 0; i < countCourses; i++)
    {
        if(courses[i].id == id)
        {
            cout << "Course Found\n";
            cout << courses[i].name << endl;
            return;
        }
    }
    cout << "Course Not Found\n";
}
int main()
{
    int choice;
    do
    {
        cout << "\n1. Add Course";
        cout << "\n2. Display Courses";
        cout << "\n3. Search Course";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: addCourse(); break;
            case 2: displayCourses(); break;
            case 3: searchCourse(); break;
        }
    } while(choice != 4);
    return 0;
}
