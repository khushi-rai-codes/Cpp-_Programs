#include <iostream>
using namespace std;
class Product
{
    int id;
    string name;
    int quantity;
public:
    void input()
    {
        cout << "Enter Product ID: ";
        cin >> id;
        cout << "Enter Product Name: ";
        cin >> name;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }
    void display()
    {
        cout << "\nProduct Details\n";
        cout << "ID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Quantity : " << quantity << endl;
    }
};
int main()
{
    Product p;
    p.input();
    p.display();
    return 0;
}
