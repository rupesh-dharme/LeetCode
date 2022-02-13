class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> answer = {first};
        for (auto num : encoded) {
            answer.push_back(num^answer.back());
        }
        return answer;
    }
};