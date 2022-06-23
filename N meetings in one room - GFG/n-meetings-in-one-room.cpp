// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        if (n == 0) return 0;
        vector<pair<int, int>> meets;
        for (int i = 0; i < n; i++) {
            meets.push_back({start[i], end[i]});
        }
        sort(meets.begin(), meets.end());
        int count = 1, minEnd = meets[0].second;
        for (int i = 1; i < n; i++) {
            pair<int, int> meet = meets[i];
            if (meet.first <= minEnd) {
                minEnd = min(meet.second, minEnd);
            } else {
                count++;
                minEnd = meet.second;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends