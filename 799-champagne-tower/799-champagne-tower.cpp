class Solution {
public:
    double champagneTower(int poured, int qr, int qg) {
        if (qr == 0) return min(1, poured);
        vector<double> lvl = {(double)poured};
        int j = 0;
        while (j < qr) {
            vector<double> temp;
            temp.push_back(max((lvl[0]-1)/2, 0.0));
            for (int i = 1; i < lvl.size(); i++) {
                temp.push_back(max((lvl[i-1]-1)/2, 0.0) + max((lvl[i]-1)/2, 0.0));
            }
            temp.push_back(temp[0]);
            lvl = temp;
            j++;
        }
        return min(1.0, lvl[qg]);
    }
};