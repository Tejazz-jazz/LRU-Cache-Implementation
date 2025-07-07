#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<int> lruList; // stores keys
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        // Move accessed key to front (most recently used)
        lruList.erase(cache[key].second);
        lruList.push_front(key);
        cache[key].second = lruList.begin();

        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update value and move to front
            lruList.erase(cache[key].second);
        } else {
            if (cache.size() == capacity) {
                // Evict least recently used key
                int lruKey = lruList.back();
                lruList.pop_back();
                cache.erase(lruKey);
            }
        }

        lruList.push_front(key);
        cache[key] = {value, lruList.begin()};
    }

    void display() {
        cout << "Current LRU state (most recent first): ";
        for (int key : lruList) {
            cout << key << " ";
        }
        cout << endl;
    }
};

// Demo usage
int main() {
    LRUCache cache(2); // capacity = 2
    cache.put(1, 10);
    cache.put(2, 20);
    cache.display();         // 2 1
    cout << cache.get(1) << endl; // 10
    cache.display();         // 1 2
    cache.put(3, 30);        // evicts key 2
    cache.display();         // 3 1
    cout << cache.get(2) << endl; // -1 (not found)
    return 0;
}
