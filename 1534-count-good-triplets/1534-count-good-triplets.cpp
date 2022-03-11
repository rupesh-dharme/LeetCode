class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0, n = arr.size();
        for (int i = 0; i < n-2; i++) {
            for (int j = i+1; j < n-1; j++) {
                for (int k = j+1; k < n; k++) {
                    if (abs(arr[j] - arr[i]) <= a && abs(arr[k] - arr[j]) <= b && abs(arr[i] - arr[k]) <= c) count++;
                }
            }
        }
        return count;
    }
};