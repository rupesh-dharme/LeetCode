// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

// class Solution{
//   public:
//     int maxArea(int M[MAX][MAX], int n, int m) {
//         vector<int> heights(m, 0);
//         int area = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (M[i][j] == 1) heights[j]++;
//                 else heights[j] = 0;
//             }
//             area = max(area, mah(heights, m));
//         }
//         return area;
//     }
//     int mah(vector<int> &arr, int n) {
//         vector<int> right(n, n), left(n, -1);
//         stack<pair<int, int>> stack;
//         for (int i = n-1; i >= 0; --i) {
//             if (!stack.size()) {}
//             else if (stack.top().first < arr[i]) right[i] = stack.top().second;
//             else if (stack.top().first >= arr[i]) {
//                 while (stack.size() && stack.top().first >= arr[i]) stack.pop();
//                 if (stack.size()) right[i] = stack.top().second;
//             }
//             stack.push({arr[i], i});
//         }
//         while (stack.size()) stack.pop();
//         for (int i = 0; i < n; ++i) {
//             if (!stack.size()) {}
//             else if (stack.top().first < arr[i]) left[i] = stack.top().second;
//             else if (stack.top().first >= arr[i]) {
//                 while (stack.size() && stack.top().first >= arr[i]) stack.pop();
//                 if (stack.size()) left[i] = stack.top().second;
//             }
//             stack.push({arr[i], i});
//         }
//         int area = 0;
//         for (int i = 0; i < n; i++){
//             area = max(area, (right[i] - left[i] - 1) * arr[i]);
//         }
//         return area;
//     }
// };

class Solution{
  private:
  vector<int> nextSmallerElement(int* arr , int n){
      vector<int> ans(n);
      stack<int> s;
      s.push(-1);
      for(int i = n-1;i>=0 ;i--){
          int curr  = arr[i];
          while(s.top()!= -1 && arr[s.top()]>= curr){
              s.pop();
          }
          ans[i] = s.top();
          s.push(i);
      }
      return ans;
  }
   
   vector<int> prevSmallerElement(int* arr , int n){
      vector<int>ans(n);
      stack<int> s;
      s.push(-1);
      for(int i = 0; i<n;i++){
          int curr = arr[i];
          while(s.top()!= -1 && arr[s.top()]>= curr){
              s.pop();
          }
          ans[i] = s.top();
          s.push(i);
      }
      return ans;
  }
  
  int largestArea(int* heights , int n){
      
      vector<int> next(n);
      next = nextSmallerElement(heights , n);
      vector<int> prev(n);
      prev = prevSmallerElement(heights,n);
      
      int area = INT_MIN;
      
      for(int i = 0 ; i<n ;i++){
          int l = heights[i];
          if(next[i] == -1){
              next[i] = n;
          }
          int b = next[i] - prev[i] -1;
          int newArea = l*b;
          area = max(area, newArea);
      }
      return area;
  }
  
  public:
   int maxArea(int M[MAX][MAX], int n, int m) {
       // Your code here
       
       // step 1 compute area for 1st line 
       int area = largestArea(M[0],m);
       
       // add next line to the previous line and compute area then select max
       for(int i = 1;i<n ; i++ ){
           for(int j = 0; j<m; j++){
               if(M[i][j] == 1){
                   M[i][j] = M[i][j] + M[i-1][j];
               }
               else
                   M[i][j] = 0;
               }
               int newArea = largestArea(M[i],m);
               area = max(area,newArea);
           }
       return area;
   }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends