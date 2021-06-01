#include<bits/stdc++.h>
using namespace std;

/*
* TC -- O(n^2)
* SC -- O(n)
*/
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    
    int *dp = new int[n]{0};
    dp[0] = 1;
    
    int res = 1;
    
    for(int i = 1;i<n;i++)
    {
        int maxx = 1;
        for(int j = i-1;j>=0;j--)
        {
            
            if(arr[j] < arr[i])
            {
                int cur = dp[j] + 1;
                //Compare curr j with this loop maxx so far
                if(cur > maxx)
                    maxx = cur;
                
            }
        }
        dp[i] = maxx;
        if(res < dp[i])
            res = dp[i];
    }
    
    delete [] dp;
    return res;
}
