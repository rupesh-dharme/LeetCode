class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        int n = target.size();
        for (int i = 0; i < n; i++) {
            mp[target[i]]++;
            mp[arr[i]]--;
        }
        for (auto [num, freq] : mp) {
            if (freq) return false;
        }
        return true;
    }
    
    // bool canBeEqual(vector<int>& target, vector<int>& arr) {
    //     unordered_map<int, int> a, b;
    //     int n = target.size();
    //     for (int i = 0; i < n; i++) {
    //         a[target[i]]++;
    //         b[arr[i]]++;
    //     }
    //     return a == b ? true : false;
    // }
};