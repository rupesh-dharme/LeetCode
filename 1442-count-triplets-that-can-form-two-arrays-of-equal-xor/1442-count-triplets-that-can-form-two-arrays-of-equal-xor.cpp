class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            int xri = 0;
            for (int j = i+1; j < n; j++) {
                int xrj = 0;
                xri ^= arr[j-1];
                for (int k = j; k < n; k++) {
                    xrj ^= arr[k];
                    if (xrj == xri) {count++;}
                }
                
            }
        }
        return count;
    }
};