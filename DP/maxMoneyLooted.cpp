/*
*TC --> O(2^n)
*SC --> O(1)
*/
int maxMoneyLooted_BF(int *arr, int n)
{
	//Write your code here
    if(n <=0)
        return 0;
    
    //Decision
    return max(arr[n-1]+maxMoneyLooted_BF(arr,n-2),maxMoneyLooted_BF(arr,n-1));
}

/*
*TC --> O(n)
*SC --> O(n)
*/
int maxMoneyLooted_Mem(int *arr, int n, int *dp)
{
    if(n<=0)
        return 0;
    
    if(dp[n]!=-1)
        return dp[n];
    
    dp[n] = max(arr[n-1]+maxMoneyLooted_Mem(arr,n-2,dp),maxMoneyLooted_Mem(arr,n-1,dp));
    
    return dp[n];
}

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    
    //Initialization
    int *dp = new int[n+1];
    for(int i = 0;i<=n;i++)
    {
        dp[i] = -1;
    }
    
    return maxMoneyLooted_Mem(arr,n,dp);

}

/*
*TC --> O(n)
*SC --> O(n)
*/

int maxMoneyLooted_DP(int *arr, int n)
{
	//Write your code here
    
    //Initialization
    int *dp = new int[n];
    
    dp[0] = arr[0];
    dp[1] = arr[1];
    
    for(int i = 2;i<n;i++)
    {
        dp[i] = max(arr[i]+dp[i-2],
                   dp[i-1]);
    }
    
    return dp[n-1];

}


