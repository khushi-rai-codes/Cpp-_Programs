#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class LRUCache
{
private:
    int capacity;
    list<int> cache;
    unordered_map<int, list<int>::iterator> position;
public:
    LRUCache(int size)
    {
        capacity = size;
    }
    void access(int key)
    {
        if (position.find(key) != position.end())
        {
            cache.erase(position[key]);
        }
        else if (cache.size() == capacity)
        {
            int last = cache.back();
            cache.pop_back();
            position.erase(last);
        }
        cache.push_front(key);
        position[key] = cache.begin();
    }
    void display()
    {
        cout << "Cache: ";
        for (int key : cache)
        {
            cout << key << " ";
        }
        cout << endl;
    }
};
int main()
{
    LRUCache cache(3);
    cache.access(10);
    cache.access(20);
    cache.access(30);
    cache.display();
    cache.access(10);
    cache.display();
    cache.access(40);
    cache.display();
    return 0;
}
