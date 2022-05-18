// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        vector<int> result(n);
        stack<int> stack;
        for (int i = 0; i < n; i++) {
            if (!stack.size()) result[i] = -1;
            else if (stack.top() < a[i]) result[i] = stack.top();
            else if (stack.top() >= a[i]) {
                while (stack.size() && stack.top() >= a[i]) {
                    stack.pop();
                }
                if (stack.size()) {
                    result[i] = stack.top();
                } else {
                    result[i] = -1;
                }
            }
            stack.push(a[i]);
        }
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends