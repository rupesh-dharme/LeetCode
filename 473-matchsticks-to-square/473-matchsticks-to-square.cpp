class Solution {
    bool dfs(vector<int> &sidesLength,const vector<int> &matches, int index, const int target) {
        if (index == matches.size())
            return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
        for (int i = 0; i < 4; ++i) {
            if (sidesLength[i] + matches[index] > target) // first
                continue;
            int j = i;
            while (--j >= 0) // third
                if (sidesLength[i] == sidesLength[j]) 
                    break;
            if (j != -1) continue;
            sidesLength[i] += matches[index];
            if (dfs(sidesLength, matches, index + 1, target))
                return true;
            sidesLength[i] -= matches[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = 0;
        for (const int val: nums) {
            sum += val;
        }
        if (sum % 4 != 0) return false;
        sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;}); // second
        vector<int> sidesLength(4, 0);
        return dfs(sidesLength, nums, 0, sum / 4);
    }
};

// class Solution {
// private:
//     int a = 0, b = 0, c = 0,  d = 0;
//     bool dp[15];
// public:
//     bool solve(vector<int> &m, int i, int n) {
//         if (i == n) {
//             if (a == b && b == c && c == d) return true;
//             return false;
//         }
//         if (dp[i] != false) return dp[i];
        
//         a += m[i];
//         if (solve(m, i+1, n)) return true;
//         a -= m[i];
        
//         b += m[i];
//         if (solve(m, i+1, n)) return true;
//         b -= m[i];
        
//         c += m[i];
//         if (solve(m, i+1, n)) return true;
//         c -= m[i];
        
//         d += m[i];
//         if (solve(m, i+1, n)) return true;
//         d -= m[i];
        
//         return false;
//     }
//     bool makesquare(vector<int>& matchsticks) {
//         memset(dp, false, sizeof dp);
//         return solve(matchsticks, 0, matchsticks.size());
//     }
// };