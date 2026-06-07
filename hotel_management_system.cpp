#include<iostream>
using namespace std;
struct Guest
{
    int room;
    string name;
};
Guest guests[100];
int countGuests = 0;
void bookRoom()
{
    cout << "Enter Room Number: ";
    cin >> guests[countGuests].room;
    cin.ignore();
    cout << "Enter Guest Name: ";
    getline(cin, guests[countGuests].name);
    countGuests++;
    cout << "Room Booked Successfully\n";
}
void displayGuests()
{
    for(int i = 0; i < countGuests; i++)
    {
        cout << "\nRoom: " << guests[i].room;
        cout << "\nGuest: " << guests[i].name << endl;
    }
}
void checkoutGuest()
{
    int room;
    cout << "Enter Room Number: ";
    cin >> room;
    for(int i = 0; i < countGuests; i++)
    {
        if(guests[i].room == room)
        {
            for(int j = i; j < countGuests - 1; j++)
                guests[j] = guests[j + 1];
            countGuests--;
            cout << "Guest Checked Out\n";
            return;
        }
    }
    cout << "Room Not Found\n";
}
int main()
{
    int choice;
    do
    {
        cout << "\n1. Book Room";
        cout << "\n2. View Guests";
        cout << "\n3. Check Out";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: bookRoom(); break;
            case 2: displayGuests(); break;
            case 3: checkoutGuest(); break;
        }
    } while(choice != 4);
    return 0;
}
