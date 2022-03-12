class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for (auto& row : image) {
            int l = 0, r = n-1;
            while (l < r) {
                row[l] ^= 1; row[r] ^= 1;
                swap(row[l++], row[r--]);
            }
            if (n%2) row[l] ^= 1;
        }
        return image;
    }
};