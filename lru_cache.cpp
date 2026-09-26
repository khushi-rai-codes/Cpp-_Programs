#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    int capacity;

    list<pair<int, int>> cache;

    unordered_map<int, list<pair<int, int>>::iterator> position;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (position.find(key) == position.end()) {
            return -1;
        }

        auto it = position[key];
        int value = it->second;

        cache.erase(it);

        cache.push_front({key, value});
        position[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        if (position.find(key) != position.end()) {
            cache.erase(position[key]);
        } else if ((int)cache.size() == capacity) {
            int leastRecentlyUsed = cache.back().first;

            cache.pop_back();
            position.erase(leastRecentlyUsed);
        }

        cache.push_front({key, value});
        position[key] = cache.begin();
    }

    void display() {
        cout << "Cache: ";

        for (auto item : cache) {
            cout << "(" << item.first << ", " << item.second << ") ";
        }

        cout << endl;
    }
};

int main() {
    int capacity;

    cout << "Enter cache capacity: ";
    cin >> capacity;

    if (capacity <= 0) {
        cout << "Invalid capacity." << endl;
        return 0;
    }

    LRUCache cache(capacity);

    int choice;

    do {
        cout << "\n===== LRU CACHE =====\n";
        cout << "1. Put\n";
        cout << "2. Get\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int key, value;

            cout << "Enter key: ";
            cin >> key;

            cout << "Enter value: ";
            cin >> value;

            cache.put(key, value);
            cout << "Value inserted.\n";
        }
        else if (choice == 2) {
            int key;

            cout << "Enter key: ";
            cin >> key;

            int value = cache.get(key);

            if (value == -1) {
                cout << "Key not found.\n";
            } else {
                cout << "Value: " << value << endl;
            }
        }
        else if (choice == 3) {
            cache.display();
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
