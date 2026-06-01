#include<iostream>
using namespace std;
struct Item
{
    int id;
    string name;
};
Item items[100];
int countItems = 0;
void addItem()
{
    cout << "Enter Item ID: ";
    cin >> items[countItems].id;
    cin.ignore();
    cout << "Enter Item Name: ";
    getline(cin, items[countItems].name);
    countItems++;
    cout << "Item Added Successfully\n";
}
void displayItems()
{
    for(int i = 0; i < countItems; i++)
    {
        cout << "\nID: " << items[i].id;
        cout << "\nName: " << items[i].name << endl;
    }
}
void searchItem()
{
    int id;
    cout << "Enter Item ID: ";
    cin >> id;
    for(int i = 0; i < countItems; i++)
    {
        if(items[i].id == id)
        {
            cout << "Item Found\n";
            cout << items[i].name << endl;
            return;
        }
    }
    cout << "Item Not Found\n";
}
int main()
{
    int choice;
    do
    {
        cout << "\n1. Add Item";
        cout << "\n2. Display Items";
        cout << "\n3. Search Item";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                addItem();
                break;
            case 2:
                displayItems();
                break;
            case 3:
                searchItem();
                break;
        }
    } while(choice != 4);
    return 0;
}
