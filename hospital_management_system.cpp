#include<iostream>
using namespace std;
struct Patient
{
    int id;
    string name;
};
Patient patients[100];
int countPatients = 0;
void addPatient()
{
    cout << "Enter Patient ID: ";
    cin >> patients[countPatients].id;
    cin.ignore();
    cout << "Enter Patient Name: ";
    getline(cin, patients[countPatients].name);
    countPatients++;
    cout << "Patient Added Successfully\n";
}
void displayPatients()
{
    for(int i = 0; i < countPatients; i++)
    {
        cout << "\nID: " << patients[i].id;
        cout << "\nName: " << patients[i].name << endl;
    }
}
void searchPatient()
{
    int id;
    cout << "Enter Patient ID: ";
    cin >> id;
    for(int i = 0; i < countPatients; i++)
    {
        if(patients[i].id == id)
        {
            cout << "Patient Found\n";
            cout << patients[i].name << endl;
            return;
        }
    }
    cout << "Patient Not Found\n";
}
int main()
{
    int choice;
    do
    {
        cout << "\n1. Add Patient";
        cout << "\n2. Display Patients";
        cout << "\n3. Search Patient";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: searchPatient(); break;
        }
    } while(choice != 4);
    return 0;
}
