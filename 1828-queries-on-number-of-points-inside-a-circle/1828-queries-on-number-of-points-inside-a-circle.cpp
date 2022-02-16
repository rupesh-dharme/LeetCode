class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> inside;
        for (int j = 0; j < queries.size(); j++) {
            int c = 0;
            for (auto point : points) {
                if (distance(point[0], point[1], queries[j][0], queries[j][1]) <= queries[j][2]) c++;
            }
            inside.push_back(c);
        }
        return inside;
    }
    
    double distance(int a, int b, int c, int d) {
        return sqrt(pow((c-a),2) + pow((d-b), 2));
    }
};