#include<iostream>
using namespace std;
int seats[10] = {0};
void displaySeats()
{
    for(int i = 0; i < 10; i++)
    {
        cout << "Seat " << i + 1 << " : "
             << (seats[i] ? "Booked" : "Available")
             << endl;
    }
}
int main()
{
    int choice, seat;
    do
    {
        cout << "\n1. View Seats";
        cout << "\n2. Book Seat";
        cout << "\n3. Cancel Seat";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                displaySeats();
                break;
            case 2:
                cout << "Enter Seat Number: ";
                cin >> seat;
                if(seat >= 1 && seat <= 10 && !seats[seat-1])
                {
                    seats[seat-1] = 1;
                    cout << "Seat Booked\n";
                }
                else
                {
                    cout << "Invalid/Already Booked\n";
                }
                break;
            case 3:
                cout << "Enter Seat Number: ";
                cin >> seat;
                if(seat >= 1 && seat <= 10 && seats[seat-1])
                {
                    seats[seat-1] = 0;
                    cout << "Booking Cancelled\n";
                }
                else
                {
                    cout << "Seat Not Booked\n";
                }
                break;
        }
    } while(choice != 4);
    return 0;
}
