// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

// class Solution{
// public:
//     vector<int> querySum(int n, int arr[], int q, int queries[])
//     {
//         vector<int> seg(100000);
        
//         build(0, arr, 0, n-1, seg);
//         vector<int> res;
//         for (int i = 0; i < 2*q; i += 2) {
//             res.push_back(query(0, arr, 0, n-1, queries[i]-1, queries[i+1]-1, seg));
//         }
//         return res;
//     }
//     void build(int node, int arr[], int l, int r, vector<int> &seg) {
//         if (l == r) {
//             seg[node] = arr[l];
//             return;
//         }
//         int mid = (l+r)/2;
//         build(node*2+1, arr, l, mid, seg);
//         build(node*2+2, arr, mid+1, r, seg);
//         seg[node] = seg[node*2 + 1] + seg[node*2 + 2];
//     }
//     int query(int node, int arr[], int low, int high, int l, int r, vector<int> &seg) {
//         if (low >= l && high <= r) return seg[node];
//         if (l > high || r < low) return 0;
//         int mid = low + (high - low)/2;
//         int left = query(node*2+1, arr, low, mid, l, r, seg);
//         int right = query(node*2+2, arr, mid+1, high, l, r, seg);
//         return left + right;
//     }
// };



class Solution{
private:
    int seg[100000];
public:
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        build(0, arr, 0, n-1);
        vector<int> result;
        for (int i = 0; i < 2*q; i += 2) {
            result.push_back(query(0, 0, n-1, queries[i]-1, queries[i+1]-1));
        }
        return result;
    }
    
    void build(int ind, int arr[], int l, int r) {
        if (l == r) {
            seg[ind] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(ind*2 + 1, arr, l, mid);
        build(ind*2 + 2, arr, mid + 1, r);
        seg[ind] = seg[ind*2 + 1] + seg[ind*2 + 2];
    }
    int query(int ind, int low, int high, int l, int r) {
        if (l <= low && high <= r) return seg[ind];
        if (low > r || high < l) return 0;
        int mid = low + (high - low)/2;
        int left = query(ind*2 + 1, low, mid, l, r);
        int right = query(ind*2 + 2, mid + 1, high, l, r);
        return left + right;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends