// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends


/* The functions which 
builds the segment tree */
int seg[4005] = {0};

void build(int node, int low, int high, int arr[]) {
    if (low == high) {
        seg[node] = arr[low];
        return;
    }
    int m = low + (high - low)/2;
    build(node*2 + 1, low, m, arr);
    build(node*2 + 2, m + 1, high, arr);
    seg[node] = min(seg[node*2 + 1], seg[node*2 + 2]);
}

int *constructST(int arr[],int n)
{
  //Your code here
  build(0, 0, n-1, arr);
  return seg;
}

int minimum(int node, int low, int high, int l, int r, int seg[]) {
    if (low >= l && r >= high) return seg[node];
    if (low > r || high < l) return INT_MAX;
    int m = low + (high - low) / 2;
    int left = minimum(node*2 + 1, low, m, l, r, seg);
    int right = minimum(node*2 + 2, m + 1, high, l, r, seg);
    return min(left, right);
}
/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
//Your code here
    return minimum(0, 0, n-1, a, b, st);
}