// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        int mx = 0, n = S.size();
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < n; i++) {
            if (S[i] == '(') stk.push(i);
            else {
                stk.pop();
                if (stk.size()) mx = max(mx, i - stk.top());
                else stk.push(i);
            }
        }
        return mx;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends