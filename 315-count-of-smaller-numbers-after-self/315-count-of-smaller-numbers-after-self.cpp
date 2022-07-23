class Solution {
public:
    void merge(vector<int> &result, vector<pair<int, int>> &index, int left, int mid, int right) {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (index[i].first <= index[j].first) {
                temp[k++] = index[j++];
            } else {
                result[index[i].second] += right - j + 1;
                temp[k++] = index[i++];
            }
        }
        
        while (i <= mid) temp[k++] = index[i++];
        while (j <= right) temp[k++] = index[j++];
        
        for (i = left; i <= right; i++) index[i] = temp[i - left];
    }
    void mergeSort(vector<int> &result, vector<pair<int, int>> &index, int i, int j) {
        if (i < j) {
            int mid = i + (j - i)/2;
            mergeSort(result, index, i, mid);
            mergeSort(result, index, mid+1, j);
            merge(result, index, i, mid, j);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> index(n);
        for (int i = 0; i < n; i++) index[i] = {nums[i], i};
        
        vector<int> result(n, 0);
        mergeSort(result, index, 0, n-1);
        return result;
    }
};