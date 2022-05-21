// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<int> right(n, n), left(n, -1);
        stack<pair<long long, int>> stack;
        for (int i = n-1; i >= 0; --i) {
            if (!stack.size()) {}
            else if (stack.top().first < arr[i]) right[i] = stack.top().second;
            else if (stack.top().first >= arr[i]) {
                while (stack.size() && stack.top().first >= arr[i]) stack.pop();
                if (stack.size()) right[i] = stack.top().second;
            }
            stack.push({arr[i], i});
        }
        while (stack.size()) stack.pop();
        for (int i = 0; i < n; ++i) {
            if (!stack.size()) {}
            else if (stack.top().first < arr[i]) left[i] = stack.top().second;
            else if (stack.top().first >= arr[i]) {
                while (stack.size() && stack.top().first >= arr[i]) stack.pop();
                if (stack.size()) left[i] = stack.top().second;
            }
            stack.push({arr[i], i});
        }
        long long area = 0;
        for (int i = 0; i < n; i++){
            area = max(area, (right[i] - left[i] - 1) * arr[i]);
        }
        return area;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends