/*
*T.C - O(n*sqrt(n))
*S.C - O(n)
*/
#include <bits/stdc++.h>
using namespace std;

bool perfectSquare(int n)
{
    int itr = n/2;
    for(int i=2;i<=itr;i++)
    {
        if(i*i==n)
            return true;
        if(i*i>n)
            return false;
        
    }
    return false;
}

int minCount(int n)
{
	//Write your code here
    
    if(perfectSquare(n))
        return 1;
    
    int *dp = new int[n+1];
    
    memset(dp,0,sizeof dp);
    
    dp[0] = 0;
    dp[1] = 1;
    
    //fill all the perfect square
    for(int i = 2;i<=n;i++)
    {
        dp[i] = i;
        
        for(int j=1;i-(j*j)>=0;j++)
        {
            dp[i] = min(dp[i],dp[i - (j*j)]);
        }
        //for sum as squares of 1
      	dp[i]+=1;  
    }
    
    int res = dp[n];
    delete [] dp;
    return res;
}





int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
