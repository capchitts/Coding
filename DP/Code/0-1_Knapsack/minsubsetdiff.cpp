#include <bits/stdc++.h>
using namespace std;

vector<int> subsetsum(int arr[],int n, int sum)
{
	vector<int> v;
	bool dp[n + 1][sum + 1]; 
  
    
    	for (int i = 0; i <= n; i++) 
        	dp[i][0] = true; 
  
  
    	for (int i = 1; i <= sum; i++) 
        	dp[0][i] = false; 
  
    	// Fill the subset table in botton up manner 
    	for (int i = 1; i <= n; i++) 
    	{ 
        	for (int j = 1; j <= sum; j++) 
        	{ 
             
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
	
	for(int i = 0;i<=sum/2;i++)
	{
		if(dp[n][i]==1)
		 	v.push_back(i);

	}
	
	return v;
}

int minsubsetdiff(int arr[], int n, int range)
{
	vector<int> v = subsetsum(arr,n,range);
	int mn = INT_MAX;
	
	for(int i = 0;i<v.size();i++)
	{

			mn = min(mn ,range-2*v[i]);


	}
	
	return mn;
}


int main()
{
	int arr[] = {1,2,7};
	int n = 3;
	int range = 10;
	
	int ans = minsubsetdiff(arr,n,range);
	cout<<"Min subset difference is: "<<ans<<endl;
	//subsetsum(arr,n,range);
	return 0;
	
}
