class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; i++) {
            res[i].resize(i+1);
            res[i][0] = res[i][i] = 1;
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> res = {{1}};
//         for (int i = 1; i < numRows; i++) {
//             vector temp1 = res.back();
//             temp1.push_back(0);
//             reverse(temp1.begin(), temp1.end());
//             vector temp2 = res.back();
//             temp2.push_back(0);
//             for (int j = 0; j < temp1.size(); j++) {
//                 temp1[j] += temp2[j];
//             }
//             res.push_back(temp1);
//         }
//         return res;
//     }
// };