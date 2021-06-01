int editDistance_Mem(string s1, string s2,int ** dp) 
{
	// Write your code here
    /*
    *  TC - O(mn)
    *  SC - O(max(m,n))
    */ 
    int m = s1.size();
    int n = s2.size();
    
    if(m<=0 || n<=0)
        return max(m,n);
    
    
    if(dp[m][n] != -1)
        return dp[m][n];

    else
    {
        if(s1[0]==s2[0])
        {
            dp[m-1][n-1] = editDistance_Mem(s1.substr(1),s2.substr(1),dp);
            dp[m][n] = dp[m-1][n-1];
        }
        else
        {
        	dp[m-1][n] = editDistance_Mem(s1.substr(1),s2,dp);
    		dp[m][n-1] = editDistance_Mem(s1,s2.substr(1),dp);
    		dp[m-1][n-1] = editDistance_Mem(s1.substr(1),s2.substr(1),dp);
        
        	dp[m][n] = 1+ min(min(dp[m-1][n],dp[m][n-1]),dp[m-1][n-1]);
        }
    }
    
    return dp[m][n];
    
}

int editDistance_Dp(string s1,string s2)
{
    int m = s1.size();
    int n = s2.size();
    
    int **dp = new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        dp[i] = new int[n+1];
        for(int j = 0;j<=n;j++)
            dp[i][j] = 0;
    }
    
    //Initialization
    //First row as col index
    for(int i = 0;i<=n;i++)
    {
        dp[0][i] = i;
    }
    //First col as row index
    for(int i = 0;i<=m;i++)
    {
        dp[i][0] = i;
    }
    
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
            }
        }
    }
    
    return dp[m][n];
}


int editDistance(string s1, string s2)
{
	//Write your code here
    /*
    int m = s1.size();
    int n = s2.size();
    
    int **dp = new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        dp[i] = new int[n+1];
        for(int j = 0;j<=n;j++)
            dp[i][j] = -1;
    }
    
    int ret = editDistance_Mem(s1, s2, dp);
    return ret;
    */
    
    //Write your code here
    return editDistance_Dp(s1,s2);
   
    
}


