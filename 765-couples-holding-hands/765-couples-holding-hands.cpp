class Solution {
private:
    unordered_map<int, int> indexof;
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        for (int i = 0; i < n; i++) indexof[row[i]] = i;
        int swaps = 0;
        for (int i = 0; i < n; i+=2) {
            int first = row[i];
            int second = first + (first % 2 ? -1 : 1);
            if (second != row[i+1]) {
                swap(row, i+1, indexof[second]);
                swaps++;
            }
        }
        return swaps;
    }
    void swap(vector<int> &arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        indexof[arr[i]] = i;
        indexof[arr[j]] = j;
    }
};