class Solution {
public:
    int minCost(vector<int>& start, vector<int>& home, vector<int>& rCosts, vector<int>& cCosts) {
        int cost = 0;
        int hr = home[0], hc = home[1], sr = start[0], sc = start[1];
        while (sr != hr) {
            if (sr > hr) sr--;
            else sr++;
            cost += rCosts[sr];
        }
        while (sc != hc) {
            if (sc > hc) sc--;
            else sc++;
            cost += cCosts[sc];
        }
        return cost;
    }
};