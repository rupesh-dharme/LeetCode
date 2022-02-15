class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer(n+1, 0);
        for (int i = 1; i <= n; i++) {
            answer[i] = answer[i&(i-1)] + 1;
        }
        return answer;
    }
};

// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> answer(n+1);
//         for (int i = 0; i <= n; i++) {
//             answer[i] = __builtin_popcount(i);
//         }
//         return answer;
//     }
// };