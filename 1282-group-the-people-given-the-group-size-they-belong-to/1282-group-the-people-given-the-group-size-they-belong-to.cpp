class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        multimap<int, int> mmp;
        vector<vector<int>> res;
        int n = groupSizes.size();
        for (int i = 0; i < n; i++) {
            mmp.insert({groupSizes[i], i});
        }
        int curr = 0;
        for (auto [grp, index] : mmp) {
            if (curr and grp == curr) {
                if (res.back().size() < grp) {
                    res.back().push_back(index);
                } else {
                    res.push_back({index});
                }
                curr = grp;
            } else if (curr == 0) {
                res.push_back({index});
                curr = grp;
            } else if (grp != curr) {
                curr = grp;
                res.push_back({index});
            }
        }
        return res;
    }
};