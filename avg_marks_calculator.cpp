#include<iostream>
using namespace std;

int main()
{
    int marks1, marks2, marks3;
    float average;

    cout << "Enter marks of 3 subjects: ";
    cin >> marks1 >> marks2 >> marks3;

    average = (marks1 + marks2 + marks3) / 3.0;

    cout << "Average Marks = " << average;

    return 0;
}
