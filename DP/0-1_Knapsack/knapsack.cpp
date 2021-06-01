#include <bits/stdc++.h>
using namespace std;


int knapsack_rec(int val[],int wt[],int n,int w)
{
	if(n==0||w==0)
		return 0;
		
	if(wt[n-1] <= w)
		return max(val[n-1]+knapsack_rec(val,wt,n-1,w-wt[n-1]),knapsack_rec(val,wt,n-1,w));
	
	return knapsack_rec(val,wt,n-1,w);
}


int knapsack(int val[],int wt[],int n,int w)
{
	int dp[n+1][w+1];
	
	//initialisation
	for(int i = 0;i<=n;i++)
	{
		dp[i][0] = 0;
	}
	
	for(int j = 0;j<=w;j++)
	{
		dp[0][j] = 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j = 1;j<=w;j++)
		{	
			if(wt[i-1]<=w)
			{
				dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			}
			
			else
			 dp[i][j] = dp[i-1][j];
		}
	}
	
	return dp[n][w];
}

int main()
{	
	int va[] = { 60, 100, 120 }; 
    	int wt[] = { 10, 20, 30 }; 
    	int w = 50; 
	int n = 3;
	
	
	cout<<endl<<"Profit gained is : "<<knapsack(va,wt,n,w)<<endl;
	cout<<endl<<"Profit gained is : "<<knapsack_rec(va,wt,n,w)<<endl;

	return 0;
}
