#include<iostream>
#include<string>
using namespace std;
string books[100];
int countBooks = 0;
void addBook()
{
    cout << "Enter book name: ";
    cin.ignore();
    getline(cin, books[countBooks]);
    countBooks++;
    cout << "Book added successfully\n";
}
void displayBooks()
{
    if(countBooks == 0)
    {
        cout << "No books available\n";
        return;
    }
    cout << "Books in Library:\n";
    for(int i = 0; i < countBooks; i++)
    {
        cout << i + 1 << ". " << books[i] << endl;
    }
}
void searchBook()
{
    string name;
    bool found = false;
    cout << "Enter book name to search: ";
    cin.ignore();
    getline(cin, name);
    for(int i = 0; i < countBooks; i++)
    {
        if(name == books[i])
        {
            cout << "Book Found\n";
            found = true;
            break;
        }
    }
    if(!found)
        cout << "Book Not Found\n";
}
int main()
{
    int choice;
    do
    {
        cout << "\n--- LIBRARY MENU ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                cout << "Exiting Program\n";
                break;
            default:
                cout << "Invalid Choice\n";
        }
    } while(choice != 4);
    return 0;
}
