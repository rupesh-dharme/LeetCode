class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string, int> ump = {{"type", 0}, {"color", 1}, {"name", 2}};
        int cnt = 0;
        for (int i = 0; i < items.size(); i++) {
            if (ruleValue == items[i][ump[ruleKey]]) cnt++;
        }
        return cnt;
    }
};