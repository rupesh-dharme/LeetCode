class LRUCache {
private:
    list<int> cache;
    list<int> :: iterator it;
    int capacity;
    int size;
    
    unordered_map<int, int> value;
    unordered_map<int, list<int>::iterator> position;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        if (value.count(key)) {
            cache.erase(position[key]);
            cache.push_front(key);
            position[key] = cache.begin();
            return value[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (this->value.count(key)) {
            this->value[key] = value;
            it = position[key];
            cache.erase(it);
            cache.push_front(key);
            position[key] = cache.begin();
        } else {
            if (size == capacity) {
                this->value.erase(cache.back());
                position.erase(cache.back());
                cache.pop_back();
            } else {
                size++;
            }
            cache.push_front(key);
            this->value[key] = value;
            position[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */