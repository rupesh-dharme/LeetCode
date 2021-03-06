class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int r = INT_MIN, n = nums.size();
        stack<int> stk;
        for( int i = n-1; i >= 0; i-- ){
            if( nums[i] < r ) return true;
            else while( !stk.empty() && nums[i] > stk.top() ){ 
              r = stk.top(); stk.pop(); 
            }
            stk.push(nums[i]);
        }
        return false;
    }
};