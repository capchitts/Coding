
int minCostPath_DP(int **input,int m, int n)
{
    int **dp = new int*[m];
    for(int i=0;i<m;i++)
    {
        dp[i] = new int[n];
    }
    
    // Initialization steps
    
    //	1.Fill last cell
    dp[m-1][n-1] = input[m-1][n-1];
    
    //	2.Fill last row in right to left manner
    for(int i = n-2;i>=0;i--)
    {
        dp[m-1][i] = input[m-1][i] + dp[m-1][i+1];
    }
    //	3.Fill last column in bottom to up manner
    for(int i = m-2;i>=0;i--)
    {
        dp[i][n-1] = input[i][n-1]+dp[i+1][n-1];
    }
    
    //Compute Step
    for(int i = m-2;i>=0;i--)
    {
        for(int j = n-2;j>=0;j--)
        {
            dp[i][j] = min(min(dp[i+1][j],dp[i][j+1]),dp[i+1][j+1])+input[i][j];
        }
    }
    
    return dp[0][0];
    
}
int minCostPath(int **input, int m, int n)
{
	//return minCostPath_BF(input,m,n,0,0);
    /*
    int **dp = new int*[m];
    for(int i=0;i<m;i++)
    {
        dp[i] = new int[n];
        for(int j = 0;j<n;j++)
        {
            dp[i][j] = -1;
        }
    }
    int res = minCostPath_Mem(input,m,n,0,0,dp);
    return dp[0][0];
    */
    
    return minCostPath_DP(input,m,n);
    
    
}
