class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int peak = 0, current = 0;
        for (auto& inc : gain) {
            current += inc;
            peak = max(peak, current);
        }
        return peak;
    }
};