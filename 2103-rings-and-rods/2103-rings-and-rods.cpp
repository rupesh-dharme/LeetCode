class Solution {
public:
    int countPoints(string r) {
        vector<vector<int>> v(10, vector<int>(3, 0));
        for (int i = 0; i < r.size(); i+=2) {
            int j = r[i] == 'R' ? 0 : r[i] == 'G' ? 1 : 2;
            v[r[i+1]-'0'][j] = 1;
        }
        int count = 0;
        for (auto vec : v) {
            if (all_of(vec.begin(), vec.end(), [](int ele) {return ele == 1;})) {
                count++;
            }
        }
        return count;
    }
};