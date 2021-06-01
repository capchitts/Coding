/*
Given n job and n person along with an n*n matrix where mat[p][i] gives the cost to perform i job by p person , task is to find min cost to do all the jobs.
Constraint 1 job can be done by only 1 person and 1 person can only do 1 job.
*/

#include<bits/stdc++.h>
using namespace std;

//Top Down approach / Iterative
int minJobCostI(int cost[4][4],int n)
{
	int *dp = new int[1<<n];
	
	for(int i = 0;i<(1<<n);i++)
		dp[i] = INT_MAX;
	
	//Entering cost for the case no job is assignd to nobody
	dp[0] = 0;
	
	for(int mask = 0;mask<((1<<n)-1);mask++)
	{
		int temp = mask;
		int num_setbits = 0;
		//Count number of set bits
		while(temp)
		{
			if((temp%2) == 1)
			 num_setbits+=1;
			
			temp = temp/2;
		}
		//run n times to find the cost to mask 1111 , starting from this mask
		for(int j = 0;j<n;j++)
		{
			//check if bit is already not set , as only unset bits are used
			if(!(mask&(1<<j)))
			{
				//cost[num_setbits][j] will give cost of total person done work till now for job j, like if num_setbits = 2 , cost of doing job j by second person.
				dp[mask|(1<<j)] = min(dp[mask|(1<<j)],dp[mask]+cost[num_setbits][j]);
			}
		}
	}
	
	return dp[(1<<n) -1];
}

//Recursion with Memoization
int minJobCost(int cost[4][4],int n, int per, int mask,int *dp)
{
	if(per>=n)
		return 0;
	
	if(dp[mask]!=INT_MAX)
	{
		return dp[mask];
	}
	
	int minn = INT_MAX;
	for(int i = 0;i<n;i++)
	{
		//check if this bit is not set , then only chose this bit else ignore
		if(!(mask&(1<<i)))
		{
			int smallAns = minJobCost(cost,n,per+1,(mask|(1<<i)),dp) + cost[per][i];
			minn = min(smallAns,minn);
		}
	}
	
	dp[mask] = minn;
	return minn;
	 
	
}

int main()
{
	int cost[4][4] = {{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};
	
	//this dp array is for mask as we are changing mask everytime and it is representing the answer when function ends i.e for case of 4 jobs when mask reaches 1111 , we get the answer.
	
	/*
	int *dp = new int[1<<4];
	
	for(int i = 0;i<(1<<4);i++)
	{
		dp[i] = INT_MAX;
	}
	
	cout<<endl<<minJobCost(cost,4,0,0,dp)<<endl;
	cout<<dp[0]<<endl;
	*/
	
	cout<<endl<<minJobCostI(cost,4)<<endl;	
	
	return 0;
}
