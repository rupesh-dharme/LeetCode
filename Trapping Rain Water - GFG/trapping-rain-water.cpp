// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        vector<int> left(n), right(n);
        
        for (int i = 0; i < n; i++) left[i] = i == 0 ? arr[i] : max(arr[i], left[i-1]);
        for (int i = n-1; i >= 0; --i) right[i] = i == n-1 ? arr[i] : max(arr[i], right[i+1]);
        
        long long water = 0;
        
        for (int i = 0; i < n; i++) {
            water += min(left[i], right[i]) - arr[i];
        }
        
        return water;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends