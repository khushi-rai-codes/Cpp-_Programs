#include <iostream>
#include <fstream>
using namespace std;
class Employee {
public:
    int id;
    string name;
    float salary;
};
int main() {
    Employee e;
    ofstream file("employee.txt");
    cout << "Enter Employee ID: ";
    cin >> e.id;
    cout << "Enter Employee Name: ";
    cin >> e.name;
    cout << "Enter Salary: ";
    cin >> e.salary;
    file << e.id << " " << e.name << " " << e.salary;
    file.close();
    cout << "Employee record saved successfully.";
    return 0;
}
