class Solution {
public:
    string removeKdigits(string nums, int k) {
        while (k > 0) {
            for (int i = 0; i < nums.size(); i++) {
                if (i!=0 and nums[i] < nums[i-1]) {
                    nums.erase(i-1, 1);
                    break;
                } else if (i == nums.size()-1) nums.erase(nums.size()-1, 1);
            }
            k--;
        }
        if (k) {
            while (k-- && nums.size()) {
                nums.erase(nums.size()-1);
            }
        }
        if (k) return "0";
        while(nums.size() && nums[0] == '0') nums.erase(0, 1);
        return nums.size() ? nums : "0";
    }
};