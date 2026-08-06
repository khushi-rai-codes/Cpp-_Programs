#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int> numbers;
    numbers.insert(50);
    numbers.insert(20);
    numbers.insert(10);
    numbers.insert(40);
    numbers.insert(30);
    cout << "Elements in Set:\n";
    for(auto value : numbers)
        cout << value << " ";
    cout << "\n\nSearching 20...\n";
    if(numbers.find(20) != numbers.end())
        cout << "20 Found";
    else
        cout << "20 Not Found";
    return 0;
}
