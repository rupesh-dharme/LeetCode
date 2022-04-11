class BrowserHistory {
public:
    string curr;
    stack<string> history;
    stack<string> future;
    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        history.push(curr);
        while (future.size()) future.pop();
        curr = url;
    }
    
    string back(int steps) {
        while(steps-- && history.size()) {
            future.push(curr);
            curr = history.top(); history.pop();
        }
        return curr;
    }
    
    string forward(int steps) {
        while(steps-- && future.size()) {
            history.push(curr);
            curr = future.top(); future.pop();
        }
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */