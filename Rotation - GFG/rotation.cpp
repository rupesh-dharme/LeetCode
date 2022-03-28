// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int l = 0, r = n-1;
	    while (l <= r) {
	        if (arr[l] <= arr[r]) return l;
	        int m = l + (r - l)/2;
	        int next = (m + 1) % n;
	        int prev = (m + n - 1) % n;
	        if (arr[next] > arr[m] && arr[prev] > arr[m]) return m;
	        if (arr[l] <= arr[m]) l = m + 1;
	        else r = m - 1;
	    }
	    return 0;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends