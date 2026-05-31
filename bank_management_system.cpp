#include<iostream>
using namespace std;
class Account
{
public:
    int accountNumber;
    double balance;
};
int main()
{
    Account acc;
    int choice;
    double amount;
    cout << "Enter Account Number: ";
    cin >> acc.accountNumber;
    acc.balance = 0;
    do
    {
        cout << "\n1. Deposit";
        cout << "\n2. Withdraw";
        cout << "\n3. Check Balance";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter Amount: ";
                cin >> amount;
                acc.balance += amount;
                break;
            case 2:
                cout << "Enter Amount: ";
                cin >> amount;
                if(amount <= acc.balance)
                    acc.balance -= amount;
                else
                    cout << "Insufficient Balance\n";
                break;
            case 3:
                cout << "Balance = " << acc.balance << endl;
                break;
        }
    } while(choice != 4);
    return 0;
}
