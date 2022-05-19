class StockSpanner {
private:
    stack<pair<int, int>> stack;
    int index = 0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res;
        while(stack.size() && stack.top().first <= price) stack.pop();
        if (stack.size()) res = index - stack.top().second;
        else res = index+1;
        stack.push({price, index});
        index++;
        return res;
    }
};

// class StockSpanner {
// public:
//     stack<pair<int, int>> stk;
//     StockSpanner() {
        
//     }
    
//     int next(int price) {
//         int cnt = 1;
//         while (stk.size() && stk.top().first <= price) {
//             cnt += stk.top().second;
//             stk.pop();
//         }
//         stk.push({price, cnt});
//         return cnt;
//     }
// };

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */