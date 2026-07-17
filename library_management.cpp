#include <iostream>
using namespace std;
class Book
{
    int id;
    string title;
    bool issued;
public:
    void input()
    {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Book Title: ";
        getline(cin, title);
        issued = false;
    }
    void issueBook()
    {
        issued = true;
    }
    void display()
    {
        cout << "\nBook ID : " << id;
        cout << "\nTitle : " << title;
        cout << "\nStatus : " << (issued ? "Issued" : "Available") << endl;
    }
};
int main()
{
    Book b;
    b.input();
    b.issueBook();
    b.display();
    return 0;
}
