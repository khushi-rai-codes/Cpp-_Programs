#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> pq;
    pq.push(25);
    pq.push(10);
    pq.push(50);
    pq.push(30);
    pq.push(5);
    cout << "Priority Queue Elements:\n";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
