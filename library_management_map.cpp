#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, string> library;
    int n;
    cout << "Enter number of books: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int id;
        string title;
        cout << "\nBook ID: ";
        cin >> id;
        cin.ignore();
        cout << "Book Title: ";
        getline(cin, title);
        library[id] = title;
    }
    cout << "\nLibrary Records\n";
    for (auto book : library)
    {
        cout << "ID: " << book.first
             << "  Title: " << book.second << endl;
    }
    return 0;
}
