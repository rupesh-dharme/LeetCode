class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        for (auto num : arr) mp[num]++;
        for (auto [num , count] : mp) {
            if (!st.insert(count).second) return false;
        }
        return true;
    }
};