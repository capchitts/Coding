#include <bits/stdc++.h>
using namespace std;

bool subsetsum(int arr[],int n, int sum)
{

    bool dp[n + 1][sum + 1]; 
  
    
    for (int i = 0; i <= n; i++) 
        dp[i][0] = true; 
  
  
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = false; 
  
    // Fill the subset table in botton up manner 
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
             
             if (j >= arr[i - 1]) 
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                
             else
             	dp[i][j] = dp[i - 1][j];  
        } 
    } 
  

     for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%4d", dp[i][j]); 
       printf("\n"); 
     }
  
    return dp[n][sum]; 
}


int main()
{
	int arr[] = {4,2,5,6,7} ;//{2,3,7,8,10};
	int n = 5;
	int range = 14;
	

	
	if(subsetsum(arr,n,range))
		cout<<"a subset with given sum is possible"<<endl;
	return 0;
	
}
