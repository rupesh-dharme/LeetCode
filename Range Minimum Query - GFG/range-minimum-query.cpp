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

int seg[100000];

void build(int node, int arr[], int l, int r) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    int m = l + (r - l)/2;
    build(node*2 + 1, arr, l, m);
    build(node*2 + 2, arr, m + 1, r);
    seg[node] = min(seg[node*2 + 1], seg[node*2 + 2]);
}

int *constructST(int arr[],int n)
{
//   memset(seg, INT_MAX, sizeof(seg));
  build(0, arr, 0, n-1);
//   for (int i = 0; i < 10; i++) cout << seg[i] << " ";
  return seg;
}

int query(int node, int low, int high, int l, int r) {
    if (low >= l && high <= r) return seg[node];
    if (l > high || r < low) return INT_MAX;
    int mid = (low + high) / 2;
    int left = query(node*2 + 1, low, mid, l, r);
    int right = query(node*2 + 2, mid + 1, high, l, r);
    return min(left, right);
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int l, int r)
{
    //Your code here
    return query(0, 0, n - 1, l, r);
}

