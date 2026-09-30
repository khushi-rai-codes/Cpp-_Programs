#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string text;
    int count = 0;

    cout << "Enter a string: ";
    getline(cin, text);

    for (char ch : text) {
        ch = tolower(ch);

        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u') {
            count++;
        }
    }

    cout << "Number of vowels: " << count << endl;

    return 0;
}
