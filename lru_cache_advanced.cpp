#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int capacity;

    // Most recently used entries appear at the front.
    list<pair<int, int>> cache;

    // Maps each key to its position in the list.
    unordered_map<int, list<pair<int, int>>::iterator> lookup;

public:
    explicit LRUCache(int cap) : capacity(cap) {
        if (capacity <= 0) {
            throw invalid_argument("Capacity must be positive.");
        }
    }

    int get(int key) {
        auto it = lookup.find(key);

        if (it == lookup.end()) {
            return -1;
        }

        // Move the accessed entry to the front.
        cache.splice(cache.begin(), cache, it->second);

        return it->second->second;
    }

    void put(int key, int value) {
        auto it = lookup.find(key);

        if (it != lookup.end()) {
            it->second->second = value;

            cache.splice(cache.begin(), cache, it->second);
            return;
        }

        if (static_cast<int>(cache.size()) == capacity) {
            int leastUsedKey = cache.back().first;

            lookup.erase(leastUsedKey);
            cache.pop_back();
        }

        cache.emplace_front(key, value);
        lookup[key] = cache.begin();
    }

    void display() const {
        cout << "Cache (most recent first): ";

        for (const auto& entry : cache) {
            cout << "[" << entry.first
                 << ":" << entry.second << "] ";
        }

        cout << '\n';
    }
};

int main() {
    try {
        LRUCache cache(3);

        cache.put(1, 100);
        cache.put(2, 200);
        cache.put(3, 300);

        cache.display();

        cout << "Get key 1: " << cache.get(1) << '\n';

        cache.put(4, 400);
        cache.display();

        cout << "Get key 2: " << cache.get(2) << '\n';
        cout << "Get key 3: " << cache.get(3) << '\n';

        cache.put(1, 150);
        cache.display();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
