#include <iostream>
using namespace std;
void fibonacciSeries(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    if (n <= 0) {
        cout << "Please enter a positive number.";
    } else {
        cout << "Fibonacci Series:\n";
        fibonacciSeries(n);
    }
    return 0;
}
