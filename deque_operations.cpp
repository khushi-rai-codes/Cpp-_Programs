#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> numbers;
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_front(20);
    numbers.push_front(10);
    cout << "Deque after insertion:\n";
    for (int value : numbers)
    {
        cout << value << " ";
    }
    cout << "\n\nFront Element: " << numbers.front();
    cout << "\nBack Element: " << numbers.back();
    numbers.pop_front();
    numbers.pop_back();
    cout << "\n\nDeque after removing front and back:\n";
    for (int value : numbers)
    {
        cout << value << " ";
    }
    return 0;
}
