#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
class Employee
{
public:
    int id;
    string name;
    double salary;
    void input()
    {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Salary: ";
        cin >> salary;
    }
    void display() const
    {
        cout << left
             << setw(10) << id
             << setw(25) << name
             << setw(12) << salary
             << endl;
    }
};
int main()
{
    int n;
    cout << "Enter Number of Employees: ";
    cin >> n;
    vector<Employee> emp(n);
    for(int i = 0; i < n; i++)
    {
        cout << "\nEmployee " << i + 1 << endl;
        emp[i].input();
    }
    cout << "\n---------------------------------------------\n";
    cout << left << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(12) << "Salary" << endl;
    cout << "---------------------------------------------\n";
    for(const Employee &e : emp)
        e.display();
    return 0;
}
