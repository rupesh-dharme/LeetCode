class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> answer;
        for (int i = 0; i < nums.size(); i+=2) {
            int freq = nums[i], val = nums[i+1];
            while (freq--) {
                answer.push_back(val);
            }
        }
        return answer;
    }
};