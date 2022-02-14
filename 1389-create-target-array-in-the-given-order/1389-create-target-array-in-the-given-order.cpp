class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++) {
            answer.insert(answer.begin()+index[i], 1, nums[i]);
        }
        return answer;
    }
};