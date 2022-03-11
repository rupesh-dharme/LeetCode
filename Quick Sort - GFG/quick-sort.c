// { Driver Code Starts
//Initial Template for C

#include <stdio.h>

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

 // } Driver Code Ends
//User function Template for C
void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
//Function to sort an array using quick sort algorithm.
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}
    
int partition (int arr[], int low, int high)
{
   int pivot = high;
   int l = low;
   for (int i = low; i < high; i++) {
       if (arr[i] < arr[pivot]) {
           swap(arr, i, l);
           l++;
       }
   }
   swap(arr, l, high);
   return l;
}

// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends