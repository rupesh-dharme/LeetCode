// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> prime;
    Solution() {
        prime.resize(10001);
        for (int i = 2; i < prime.size(); i++) {
            prime[i] = 1;
        }
    }
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        for (int i = 2; i <= 10000; i++) {
            if (prime[i]) {
                for (int j = i*i; j <= 10000; j+=i) prime[j] = 0;
            }
        }
        vector<int> result;
        for (int i = 2; i <= N; i++) if (prime[i]) result.push_back(i);
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends