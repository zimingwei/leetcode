class LRUCache{
private:
    struct CacheEntry {
        int key, value;
        CacheEntry(int k, int v) : key(k), value(v) {}
    };
    
    int cacheCapacity;
    list<CacheEntry> cacheList;
    unordered_map<int, list<CacheEntry>::iterator> cacheMap;
    
public:
    LRUCache(int capacity) {
        cacheCapacity = capacity;
    }
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        // Move this entry to the begin of the list
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->value;
    }
    
    void set(int key, int value) {
        if (cacheMap.find(key) == cacheMap.end()) {
            // Cache is full, so delete last entry
            if (cacheList.size() == cacheCapacity) {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(CacheEntry(key, value));
            // iterator is like a pointer
            cacheMap[key] = cacheList.begin();
        } else {
            cacheMap[key]->value = value;
            // Move this entry to the begin of the list
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        }
    }
};
