class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), k = l.size();
        vector<bool> result;
        for (int i = 0; i < k; i++) {
            vector<int> temp(nums.begin()+l[i], nums.begin()+r[i]+1);
            sort(temp.begin(), temp.end());
            int diff = temp[1] - temp[0];
            bool flag = true;
            for (int j = 1; j < temp.size(); j++) {
                if (temp[j]-temp[j-1] != diff) {
                    flag  = false;
                    break;
                }
            }
            if (flag) result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};