#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Task
{
    string name;
    int priority;
    bool operator<(const Task& other) const
    {
        return priority < other.priority;
    }
};
int main()
{
    priority_queue<Task> tasks;
    tasks.push({"Complete Assignment", 3});
    tasks.push({"Study for Exam", 5});
    tasks.push({"Read Book", 2});
    tasks.push({"Submit Project", 4});
    cout << "===== TASK SCHEDULER =====\n";
    while (!tasks.empty())
    {
        Task current = tasks.top();
        tasks.pop();
        cout << "Task: " << current.name
             << " | Priority: "
             << current.priority << endl;
    }
    return 0;
}
