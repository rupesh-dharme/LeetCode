// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    // vector<long long> nextLargerElement(vector<long long> arr, int n){
    //     stack<pair<long long, int>> stack;
    //     vector<long long> result(n, -1);
    //     for (int i = 0; i < n; i++) {
    //         while (stack.size() && stack.top().first <= arr[i]) {
    //             result[stack.top().second] = arr[i];
    //             stack.pop();
    //         }
    //         stack.push({arr[i], i});
    //     }
    //     return result;
    // }
    
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long> stack;
        vector<long long> res(n);
        for (int i = n-1; i >= 0; --i) {
            if (stack.empty()) res[i] = -1;
            else if (stack.top() > arr[i]) res[i] = stack.top();
            else if (stack.top() <= arr[i]) {
                while (stack.size() && stack.top() <= arr[i]) stack.pop();
                if (stack.size()) res[i] = stack.top();
                else res[i] = -1;
            }
            stack.push(arr[i]);
        }
        return res;
    }
    
    // vector<long long> nextLargerElement(vector<long long> arr, int n){
    //     stack<long long> stack;
    //     vector<long long> result(n, -1);
    //     for (int i = n-1; i >= 0; --i) {
    //         if (!stack.size()) {}
    //         else if (stack.top() > arr[i]) result[i] = stack.top();
    //         else if (stack.top() <= arr[i]) {
    //             while (stack.size() && stack.top() <= arr[i]) {
    //                 stack.pop();
    //             }
    //             if (!stack.size()) {}
    //             else result[i] = stack.top();
    //         }
    //         stack.push(arr[i]);
    //     }
    //     return result;
    // }
        
        
        // vector<long long> result(n, -1); // nearest greater element to the left
        // stack<int> stack;
        // for (int i = 0; i < n; i++) {
        //     if (!stack.size()) {}
        //     else if (stack.top() > arr[i]) result[i] = stack.top();
        //     else if (stack.top() <= arr[i]) {
        //         while (stack.size() && stack.top() <= arr[i]) stack.pop();
        //         if (stack.size()) {
        //             result[i] = stack.top();
        //         }
        //     }
        //     stack.push(arr[i]);
        // }
        // return result;
    // }
};





// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends