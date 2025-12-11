#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<int> lruList; 
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

     
        lruList.erase(cache[key].second);
        lruList.push_front(key);
        cache[key].second = lruList.begin();

        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
           
            lruList.erase(cache[key].second);
        } else {
            if (cache.size() == capacity) {
               
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
    LRUCache cache(2); 
    cache.put(1, 10);
    cache.put(2, 20);
    cache.display();         
    cout << cache.get(1) << endl; 
    cache.display();         
    cache.put(3, 30);      
    cache.display();         
    cout << cache.get(2) << endl; )
    return 0;
}
