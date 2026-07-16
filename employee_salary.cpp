#include <iostream>
using namespace std;
class Employee
{
private:
    string name;
    float basicSalary, hra, da, totalSalary;
public:
    void input()
    {
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
    }
    void calculate()
    {
        hra = basicSalary * 0.20;
        da = basicSalary * 0.10;
        totalSalary = basicSalary + hra + da;
    }
    void display()
    {
        cout << "\nEmployee Name : " << name << endl;
        cout << "Total Salary  : " << totalSalary << endl;
    }
};
int main()
{
    Employee emp;
    emp.input();
    emp.calculate();
    emp.display();
    return 0;
}
