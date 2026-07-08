#include <iostream>
using namespace std;
int main() {
    int n, d;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter number of left rotations: ";
    cin >> d;
    d %= n;
    cout << "Array after rotation:\n";
    for(int i = d; i < n; i++)
        cout << arr[i] << " ";
    for(int i = 0; i < d; i++)
        cout << arr[i] << " ";
    return 0;
}
