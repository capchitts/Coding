#include <bits/stdc++.h>
using namespace std;

int subsetsumcount(int arr[],int n, int sum)
{

    int dp[n + 1][sum + 1]; 
  
    
    for (int i = 0; i <= n; i++) 
        dp[i][0] = 1; 
  
  
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = 0; 
  
    // Fill the subset table in botton up manner 
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
             
             if (j >= arr[i - 1]) 
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
                
             else
             	dp[i][j] = dp[i - 1][j];  
        } 
    } 
  
     cout<<endl;
     for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%4d", dp[i][j]); 
       printf("\n"); 
     }
  
    return dp[n][sum]; 
}

int subsetCountGivenDiff(int arr[],int n, int range,int diff)
{
	/*
	Given equationa are:
	S1 + S2 = range
	S1 - S2 = diff
	result of addition of abve two is
	sum = (diff + range)/2
	This means we need to find all subsets with this sum.
	*/
	int sum = (diff+range)/2;
	
	return subsetsumcount(arr,n,sum);
}

int main()
{
	int arr[] = {1,1,2,3};
	int n = 4;
	int range = 7;
	int diff = 1;
	
	int ans = subsetCountGivenDiff(arr,n,range,diff);
	cout<<"Number of subset with given difference is: "<<ans<<endl;
	//subsetsum(arr,n,range);
	return 0;
	
}
