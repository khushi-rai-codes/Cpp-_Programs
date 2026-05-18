#include<iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    cout << "Enter size of square matrix: ";
    cin >> n;
    int matrix[n][n];
    cout << "Enter matrix elements:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        sum += matrix[i][i];
    }
    cout << "Primary diagonal sum = " << sum;
    return 0;
}
