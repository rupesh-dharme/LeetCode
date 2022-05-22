class MinStack { // using extra stack space O(n)
private:
    stack<int> s, ss;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (ss.empty() || ss.top() >= val) ss.push(val);
    }
    
    void pop() {
        int ans = s.top();
        s.pop();
        if (ss.top() == ans) ss.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ss.top();
    }
};

// class MinStack { // issues with integer overflow
// private:
//     stack<long long> stack;
//     long long min;
// public:
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if (stack.empty()) {
//             stack.push(val);
//             min = val;
//         }
//         if (val < min) {
//             stack.push((long long)2*val - min);
//             min = val;
//         }
//         else stack.push(val);
//     }
    
//     void pop() {
//         if (stack.top() < min) {
//             min = (long long)2*min - stack.top();
//             stack.pop();
//         } else stack.pop();
//     }
    
//     int top() {
//         if (stack.top() < min) return min;
//         return stack.top();
//     }
    
//     int getMin() {
//         return min;
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */