# 🧠 LRU Cache Implementation in C++

An efficient implementation of an **LRU (Least Recently Used) Cache** in C++ using `unordered_map` and `list`. This is a real-world system design concept used in memory caching, browsers, and databases.

---

## 🚀 Features

- Constant time `O(1)` `get(key)` and `put(key, value)` operations
- Uses **C++ STL** (`list` + `unordered_map`)
- Automatically evicts least recently used item when capacity is exceeded
- Displays current cache state via CLI

---

## 📁 Project Structure

