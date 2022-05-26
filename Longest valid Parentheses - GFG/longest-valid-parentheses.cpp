// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        int n = S.size(), mx = 0;
        stack<int> stack;
        stack.push(-1);
        for (int i = 0; i < n; i++) {
            if (S[i] == '(') stack.push(i);
            else {
                stack.pop();
                if (stack.size()) {
                    mx = max(mx, i - stack.top());
                }
                else stack.push(i);
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