#include<iostream>
using namespace std;
struct Book
{
    int id;
    string title;
    bool issued;
};
Book books[100];
int countBooks = 0;
void addBook()
{
    cout << "Enter Book ID: ";
    cin >> books[countBooks].id;
    cin.ignore();
    cout << "Enter Book Title: ";
    getline(cin, books[countBooks].title);
    books[countBooks].issued = false;
    countBooks++;
    cout << "Book Added Successfully\n";
}
void displayBooks()
{
    for(int i = 0; i < countBooks; i++)
    {
        cout << "\nID: " << books[i].id;
        cout << "\nTitle: " << books[i].title;
        cout << "\nStatus: "
             << (books[i].issued ? "Issued" : "Available")
             << endl;
    }
}
void issueBook()
{
    int id;
    cout << "Enter Book ID: ";
    cin >> id;
    for(int i = 0; i < countBooks; i++)
    {
        if(books[i].id == id)
        {
            books[i].issued = true;
            cout << "Book Issued\n";
            return;
        }
    }
    cout << "Book Not Found\n";
}
void returnBook()
{
    int id;
    cout << "Enter Book ID: ";
    cin >> id;
    for(int i = 0; i < countBooks; i++)
    {
        if(books[i].id == id)
        {
            books[i].issued = false;
            cout << "Book Returned\n";
            return;
        }
    }
    cout << "Book Not Found\n";
}
int main()
{
    int choice;
    do
    {
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Issue Book";
        cout << "\n4. Return Book";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
        }
    } while(choice != 5);
    return 0;
}
