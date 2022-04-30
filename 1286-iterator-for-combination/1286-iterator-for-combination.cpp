class CombinationIterator {
public:
    map<string, int> s;
    map<string, int>::iterator ptr;
    CombinationIterator(string chars, int len) {
        sort(chars.begin(), chars.end());
        int mask = 1<<chars.size();
        for (int i = 1; i < mask; i++) {
            string comb;
            int curr = i;
            int j = 0;
            while (curr) {
                if (curr & 1) {
                    comb.push_back(chars[j]);
                }
                curr >>= 1;
                j += 1;
            }
            if (comb.size() == len) s[comb]++;
        }
        ptr = s.begin();
    }
    
    string next() {
        string res = ptr->first;
        ptr++;
        return res;
    }
    
    bool hasNext() {
        if (ptr != s.end()) return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */