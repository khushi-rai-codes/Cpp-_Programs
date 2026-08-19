#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    set<int> first = {1, 2, 3, 4, 5};
    set<int> second = {3, 4, 5, 6, 7};
    set<int> difference;
    set_difference(
        first.begin(),
        first.end(),
        second.begin(),
        second.end(),
        inserter(difference, difference.begin())
    );
    cout << "Elements present in first set but not second:\n";
    for (int value : difference)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
