int mod = 1e9 + 7;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, long long> um;
        sort(arr.begin(), arr.end());
        long long result = 1;
        um[arr[0]] = 1;
        for (int i = 1; i < n; i++) {
            long long count = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0 && um.count(arr[i] /  arr[j])) {
                    count += (um[arr[i] / arr[j]] * um[arr[j]] % mod);
                }
            }
            um[arr[i]] = count;
            result += count;
        }
        return result % mod;
    }
};

// class Solution {
// public:
//     int numFactoredBinaryTrees(vector<int>& arr) {
//         unordered_set<int> us;
//         for (auto num : arr) us.insert(num);
//         unordered_map<int, unordered_set<int>> um;
//         for (int i = 0; i < arr.size(); i++) {
//             for (int j = 0; j < arr.size(); j++) {
//                 if (us.count(arr[i] * arr[j])) {
//                     um[arr[i] * arr[j]].insert(arr[i]);
//                     um[arr[i] * arr[j]].insert(arr[j]);
//                 }
//             }
//         }
//         int result = arr.size();
//         for (auto [num, st] : um) result += st.size();
//         return result;
//     }
// };