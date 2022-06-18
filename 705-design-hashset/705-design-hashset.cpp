class MyHashSet {
public:
    vector<list<int>> set;
    int size = 1000;
    MyHashSet() {
        set.resize(size);
    }
    
    int hash(int key) {
        return key%size;
    }
    
    void add(int key) {
        if (contains(key)) return;
        int index = hash(key);
        set[index].emplace_back(key);
    }
    
    void remove(int key) {
        int index = hash(key);
        auto it = find(set[index].begin(), set[index].end(), key);
        if (it == set[index].end()) return;
        set[index].erase(it);
    }
    
    bool contains(int key) {
        int index = hash(key);
        if (find(set[index].begin(), set[index].end(), key) != set[index].end()) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */