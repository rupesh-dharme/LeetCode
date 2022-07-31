class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int l = 0, r = 500;
        while (l < r) {
            int mid = l + (r - l + 1)/2;
            if (mid * (mid + 1) / 2 <= n) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};