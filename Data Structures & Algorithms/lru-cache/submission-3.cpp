
#include <algorithm>
#include <unordered_map>
#include <vector>

class LRUCache {
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    size = 0;
  }

  int get(int key) {
    auto it = cache.find(key);
    if (it != cache.end()) {
        auto vec_it = std::find(return_vector.begin(), return_vector.end(), key);
        if (vec_it != return_vector.end()) {
          return_vector.erase(vec_it);
        }
        return_vector.push_back(key); // Move to BACK (most recent)
      return it->second;
    }
    return -1;
  }

  void put(int key, int value) {
    auto it = cache.find(key);
    if (it != cache.end()) {
      it->second = value;
      auto vec_it = std::find(return_vector.begin(), return_vector.end(), key);
      if (vec_it != return_vector.end()) {
        return_vector.erase(vec_it);
      }
      return_vector.push_back(key); // Move to BACK (most recent)
      return;
    }
    if (size == capacity) {
      cache.erase(return_vector.front());
      return_vector.erase(return_vector.begin());
      size--;
    }
    cache[key] = value;
    return_vector.push_back(key);
    size++;
  }

private:
  std::vector<int> return_vector;
  std::unordered_map<int, int> cache;
  int capacity, size;
};
