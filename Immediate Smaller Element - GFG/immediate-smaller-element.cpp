// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void immediateSmaller(int *arr, int n) {
	   // vector<int> result(n); // for nearest next smaller element
	   // stack<int> stack;
	   // for (int i = n-1; i >= 0; --i) {
	   //     if (!stack.size()) result[i] = -1;
	   //     else if (stack.top() < arr[i]) result[i] = stack.top();
	   //     else if (stack.top() >= arr[i]) {
	   //         while(stack.size() && stack.top() >= arr[i]) stack.pop();
	   //         if (stack.size()) {
	   //             result[i] = stack.top();
	   //         } else result[i] = -1;
	   //     }
	   //     stack.push(arr[i]);
	   // }
	   // return result;
	    for(int i = 0; i < n-1; i++) {
	        if (arr[i+1] < arr[i]) arr[i] = arr[i+1];
	        else arr[i] = -1;
	    }
	    arr[n-1] = -1;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends