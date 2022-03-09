class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v(26, 0);
        for (auto ch : sentence) {
            v[ch - 'a'] = 1;
        }
        return all_of(v.begin(), v.end(), [](int ele) {return ele == 1;});
    }
};