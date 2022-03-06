class Solution {
public:
int maxPoints(vector<vector<int>>& points) {
        int max_points = 1;
        for (int i=0; i<points.size(); ++i) {    
            unordered_map<double,int> angle_count;
            for (int j=0; j<points.size(); ++j) {
                if (j == i) continue;
                double angle = atan2(points[j][1]-points[i][1],points[j][0]-points[i][0]);                
                angle_count[angle]++;
                max_points = max(max_points, angle_count[angle] + 1);
            }
        }
        return max_points;
    }
};