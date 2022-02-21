class MyQueue {
private:
    stack<int> s, e;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (e.size()) {
            while (e.size()) {
                s.push(e.top());
                e.pop();
            }
            s.push(x);
            while (s.size()) {
                e.push(s.top());
                s.pop();
            }
        }
        else {
            e.push(x);
        }
    }
    
    int pop() {
        int temp = e.top();
        e.pop();
        return temp;
    }
    
    int peek() {
        return e.top();
    }
    
    bool empty() {
        if(e.size()) return false;
        return true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */