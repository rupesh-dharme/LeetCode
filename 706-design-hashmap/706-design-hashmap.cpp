class Compare {
private:
    int key;
public:
    Compare(int k) {
        this->key = k;
    }
    bool operator() (pair<int, int> &a) {
        return a.first == key;
    }
};

class MyHashMap {
private:
    int size = 1000;
    vector<list<pair<int, int>>> map;
public:
    MyHashMap() {
        map.resize(size);
    }
    
    int hash(int key) {
        return key%size;
    }
    
    void put(int key, int value) {
        int index = hash(key);
        auto it = find_if(map[index].begin(), map[index].end(), [key](const pair<int, int> &a) {
            return a.first == key;
        });
        if (it == map[index].end()) map[index].emplace_back(make_pair(key, value));
        else it->second = value;
    }
    
    int get(int key) {
        int index = hash(key);
        auto it = find_if(map[index].begin(), map[index].end(), [key](const pair<int, int> &a) {
            return a.first == key;
        });
        if (it != map[index].end()) return it->second;
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        auto it = find_if(map[index].begin(), map[index].end(), Compare(key));
        if (it == map[index].end()) return;
        map[index].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */