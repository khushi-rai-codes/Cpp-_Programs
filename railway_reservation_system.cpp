#include<iostream>
using namespace std;
struct Passenger
{
    int id;
    string name;
};
Passenger passengers[100];
int countPassengers = 0;
void bookTicket()
{
    cout << "Enter Passenger ID: ";
    cin >> passengers[countPassengers].id;
    cin.ignore();
    cout << "Enter Passenger Name: ";
    getline(cin, passengers[countPassengers].name);
    countPassengers++;
    cout << "Ticket Booked Successfully\n";
}
void displayReservations()
{
    for(int i = 0; i < countPassengers; i++)
    {
        cout << "\nID: " << passengers[i].id;
        cout << "\nName: " << passengers[i].name << endl;
    }
}
void searchPassenger()
{
    int id;
    cout << "Enter Passenger ID: ";
    cin >> id;
    for(int i = 0; i < countPassengers; i++)
    {
        if(passengers[i].id == id)
        {
            cout << "Passenger Found\n";
            cout << passengers[i].name << endl;
            return;
        }
    }
    cout << "Passenger Not Found\n";
}
void cancelTicket()
{
    int id;
    cout << "Enter Passenger ID to Cancel: ";
    cin >> id;
    for(int i = 0; i < countPassengers; i++)
    {
        if(passengers[i].id == id)
        {
            for(int j = i; j < countPassengers - 1; j++)
            {
                passengers[j] = passengers[j + 1];
            }
            countPassengers--;
            cout << "Reservation Cancelled\n";
            return;
        }
    }
    cout << "Passenger Not Found\n";
}
int main()
{
    int choice;
    do
    {
        cout << "\n1. Book Ticket";
        cout << "\n2. View Reservations";
        cout << "\n3. Search Passenger";
        cout << "\n4. Cancel Ticket";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: bookTicket(); break;
            case 2: displayReservations(); break;
            case 3: searchPassenger(); break;
            case 4: cancelTicket(); break;
        }
    } while(choice != 5);
    return 0;
}
