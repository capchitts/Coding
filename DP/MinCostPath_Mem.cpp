/*
* TC --> O(m*n)
* SC --> O(m*n)
*
*/
int minCostPath_Mem(int **input,int m,int n,int x,int y,int **dp)
{
    if(x==m-1 && y==n-1)
        return input[x][y];
        
    if(x>m-1 || y>n-1)
        return INT_MAX;
    
    //Check if already calculated
    if(dp[x][y]!=-1)
        return dp[x][y];
    
    int down = minCostPath_Mem(input,m,n,x+1,y,dp);
    int right = minCostPath_Mem(input,m,n,x,y+1,dp);
    int diag = minCostPath_Mem(input,m,n,x+1,y+1,dp);
    
    dp[x][y] = input[x][y]+ min(min(down,right),diag);
    
    return dp[x][y];
}

int minCostPath_BF(int **input,int m,int n,int x,int y)
{
    if(x==m-1 && y==n-1)
        return input[x][y];
        
    if(x>m-1 || y>n-1)
        return INT_MAX;
    
    int down = minCostPath_BF(input,m,n,x+1,y);
    int right = minCostPath_BF(input,m,n,x,y+1);
    int diag = minCostPath_BF(input,m,n,x+1,y+1);
    
    return input[x][y]+ min(min(down,right),diag);
}
int minCostPath(int **input, int m, int n)
{
	//return minCostPath_BF(input,m,n,0,0);
    
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
    
}
