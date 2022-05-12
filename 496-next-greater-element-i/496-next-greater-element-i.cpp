class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        int m = nums1.size(), n = nums2.size();
        for (int i = 0; i < n; i++) mp[nums2[i]] = i;
        
        vector<int> next(n, -1);
        stack<pair<int, int>> stk;
        for (int i = 0; i < n; i++) {
            while (stk.size() && stk.top().first < nums2[i]) {
                int ind = stk.top().second;
                next[ind] = nums2[i];
                stk.pop();
            }
            stk.push({nums2[i], i});
        }
        vector<int> result(m);
        for (int i = 0; i < m; i++) {
            result[i] = next[mp[nums1[i]]];
        }
        return result;
    }
};