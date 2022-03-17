class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        if (n % 2) {
            for(int i = (-1)*(n/2); i < (n/2 + 1); i++) {
                result.push_back(i);
            }
        } else {
            for(int i = (-1)*(n/2); i < (n/2 + 1); i++) {
                if (i != 0) result.push_back(i);
            }
        }
        return result;
    }
};