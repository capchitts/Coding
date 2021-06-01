#include<bits/stdc++.h>
using namespace std;

int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    //find the length of largest square matrix with allzeros
     
    int dp[row][col];
    memset(dp,0,sizeof(dp));
    
    //initialization
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==0||j==0)
            {
                if(arr[i][j]==0)
                    dp[i][j] = 1;
                
            }
        }
    }
    
    int max_ans = 0;
    
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(arr[i][j] == 0)
                	dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1; //consider the three cells and take the minimum of that +1
            	
                else
                    dp[i][j]= 0;
            
            max_ans = max(max_ans,dp[i][j]);
        }
    }
    
    //For printing the resultant dp matrix
    /*
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
        	cout<<dp[i][j]<<" ";   
        }
        cout<<endl;
        
    }
    */
    return max_ans;
    
}
