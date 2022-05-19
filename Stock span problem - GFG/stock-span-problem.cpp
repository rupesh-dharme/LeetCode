// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int, int>> stack;
       vector<int> result(n);
       for (int i = 0; i < n; i++) {
           if (!stack.size()) result[i] = -1;
           else if (stack.top().first > price[i]) result[i] = stack.top().second;
           else if (stack.top().first <= price[i]) {
               while (stack.size() && stack.top().first <= price[i]) stack.pop();
               if (stack.size()) result[i] = stack.top().second;
               else result[i] = -1;
           }
           stack.push({price[i], i});
       }
       for (int i = 0; i < n; i++) {
           result[i] = i - result[i];
       }
       return result;
    }
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends