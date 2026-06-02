#include<iostream>
using namespace std;
struct Employee
{
    int id;
    string name;
    float salary;
};
Employee emp[100];
int countEmp = 0;
void addEmployee()
{
    cout << "Enter Employee ID: ";
    cin >> emp[countEmp].id;
    cin.ignore();
    cout << "Enter Employee Name: ";
    getline(cin, emp[countEmp].name);
    cout << "Enter Salary: ";
    cin >> emp[countEmp].salary;
    countEmp++;
    cout << "Employee Added Successfully\n";
}
void displayEmployees()
{
    for(int i = 0; i < countEmp; i++)
    {
        cout << "\nID: " << emp[i].id;
        cout << "\nName: " << emp[i].name;
        cout << "\nSalary: " << emp[i].salary << endl;
    }
}
void searchEmployee()
{
    int id;
    cout << "Enter Employee ID: ";
    cin >> id;
    for(int i = 0; i < countEmp; i++)
    {
        if(emp[i].id == id)
        {
            cout << "Employee Found\n";
            cout << "Name: " << emp[i].name << endl;
            cout << "Salary: " << emp[i].salary << endl;
            return;
        }
    }
    cout << "Employee Not Found\n";
}
int main()
{
    int choice;
    do
    {
        cout << "\n1. Add Employee";
        cout << "\n2. Display Employees";
        cout << "\n3. Search Employee";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
        }
    } while(choice != 4);
    return 0;
}
