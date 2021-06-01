int knapsack_Mem(int *weights, int *values, int n, int maxWeight, int **dp)
{
	//write your code here
    //Base Case
    if(n == 0 || maxWeight == 0)
        return 0;
    
    
    //if already present
    if(dp[n][maxWeight] != -1)
    	return dp[n][maxWeight];
    
    //Decision
    if(weights[n-1] <= maxWeight)
    {
        
        dp[n][maxWeight] = max(values[n-1]+knapsack_Mem(weights, values, n-1 , maxWeight - weights[n-1],dp),
                  knapsack_Mem(weights , values , n-1 , maxWeight,dp));
    }
    
    else
        dp[n][maxWeight] =  knapsack_Mem(weights, values,n-1,maxWeight,dp);
    
    return dp[n][maxWeight];
}

int knapsack_DP(int* weight, int* value, int n, int maxWeight)
{
    //Initialization
    int **dp = new int*[n+1];
    for(int i = 0;i<=n;i++)
    {
        dp[i] = new int[maxWeight+1];
    }
    
    //Decision
    for(int i=0;i<=n;i++)
    {
        for(int j = 0;j<=maxWeight;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else
            {
            	if(weight[i-1] <= j)// j is the weight corresponding to current column of dp matrix
            	{
                	dp[i][j] = max(value[i-1]+dp[i-1][j-weight[i-1]],
                              		dp[i-1][j]);
                
                	
            	}
            	else
                	dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][maxWeight];
    
}
int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    /*
    int **dp = new int*[n+1];
    
    for(int i = 0;i<=n;i++)
    {
        dp[i] = new int[maxWeight+1];
        for(int j = 0;j<=maxWeight;j++)
            dp[i][j] = -1;
    }
    
    
    return knapsack_Mem(weight, value, n, maxWeight,dp);
    */
    return knapsack_DP(weight, value,n,maxWeight);
    
}
