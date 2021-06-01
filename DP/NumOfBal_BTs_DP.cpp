/*
*TC ---> O(n)
*SC
*/
#include<bits/stdc++.h>
using namespace std;

int balancedBTs(int n) {
    // Write your code here
    vector<int> dp;
    
    dp.push_back(1);
    dp.push_back(1);
    
    int mod = pow(10,9) + 7;
    
    for(int i=2;i<=n;i++)
    {
        int tmp1 = (int)(((long)(dp[i-1])*dp[i-1])%mod);
        int tmp2 = (int)(((long)(dp[i-1]))*(dp[i-2]*2)%mod);
        
        dp.push_back((int)(((long)tmp1 + tmp2)%mod));
    }
    
    int res = dp[n];
    dp.clear();
    return res;
    
}
