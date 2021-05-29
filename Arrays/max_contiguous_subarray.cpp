// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int cur_sum = arr[0];
    int res = arr[0];
    
    for(int i =1;i<n;i++)
    {
        
        if(cur_sum < 0)
            cur_sum = 0;
        
        cur_sum = cur_sum+arr[i];

        if(res < cur_sum)
            res = cur_sum;
        
        
    }
    
    int sum = 0;
    for(int i =0;i<n;i++)
        sum+=arr[i];
        
    return (res > sum)?res:sum;
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
