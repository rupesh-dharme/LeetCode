class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        pair<int, int> freqa = {nums[0], 0}, freqb = {nums[1], 0};
        for (int i = 2; i < n; i++) {
            if (nums[i] == freqa.first || nums[i] == freqb.first) {
                nums[i] == freqa.first ? freqa.second++ : freqb.second++;
            }
            else {
                auto& min = freqa.second < freqb.second ? freqa : freqb;
                min.first = nums[i];
                min.second = 0;
            }
        }
        return freqa.second < freqb.second ? freqb.first : freqa.first;
    }
};