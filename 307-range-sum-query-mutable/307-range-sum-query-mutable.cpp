class NumArray {
private:
    int seg[120001];
    int high;
    vector<int> arr;
public:
    NumArray(vector<int>& nums) {
        build(0, nums, 0, nums.size()-1);
        arr = nums;
        high = nums.size();
    }
    
    void build(int node, vector<int> &nums, int low, int high) {
        if (low == high) {
            seg[node] = nums[low];
            return;
        }
        int mid = low + (high - low)/2;
        build(node*2 + 1, nums, low, mid);
        build(node*2 + 2, nums, mid + 1, high);
        seg[node] = seg[node*2 + 1] + seg[node*2 + 2];
    }
    
    void update(int index, int val) {
        // int diff = val - arr[index];
        upd(0, 0, high-1, index, val);
    }
    
    void upd(int node, int low, int high, int idx, int val) {
        if (low <= idx && idx <= high) {
            if (low == high) seg[node] = val;
            else {
                int mid = low + (high - low)/2;
                upd(node*2 + 1, low, mid, idx, val);
                upd(node*2 + 2, mid + 1, high, idx, val);
                seg[node] = seg[node*2 + 1] + seg[node*2 + 2];
            }
        }
    }
    
    int sumRange(int left, int right) {
        return sum(0, 0, high-1, left, right);
    }
    
    int sum(int node, int low, int high, int l, int r) {
        if (l <= low && high <= r) return seg[node];
        if (l > high || r < low) return 0;
        int mid = low + (high - low)/2;
        int left = sum(node*2 + 1, low, mid, l, r);
        int right = sum(node*2 + 2, mid + 1, high, l, r);
        return left + right;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */