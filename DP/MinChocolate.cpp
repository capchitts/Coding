/*
Noor is a teacher. She wants to give some chocolates to the students in her class. All the students sit in a line and each of them has a score according to performance. Noor wants to give at least 1 chocolate to each student. She distributes chocolates to them such that If two students sit next to each other then the one with the higher score must get more chocolates. Noor wants to save money, so she wants to minimise the total number of chocolates.
Note that when two students have equal score they are allowed to have different number of chocolates.
Input Format:
First Line: Integer N, the number of students in Noor’s class. 
Second Line: Each of the student's score separated by spaces.
Output Format:
Output a single line containing the minimum number of chocolates Noor must give.
Input Constraints
 1 <= N <= 100000
 1 <= score <= 100000
*/

#include <bits/stdc++.h>
using namespace std;
int getMin(int *arr, int n){
   /* Don't write main().
      Don't read input, it is passed as function argument.
      Return output and don't print it.
      Taking input and printing output is handled automatically.
   */
    
    int dp[n];
    memset(dp,0,sizeof(dp));
    
    //initialization
    if(arr[0]>arr[1])
    {
        dp[0]=2;
        dp[1]=1;
    }
    else if(arr[1]>arr[0])
    {
        dp[1]=2;
        dp[0]=1;
    }
    else
    {
        dp[0]=dp[1]=1;
    }
    
    //considering left wali condition only
    for(int i = 2;i<n;i++)
    {
        if(arr[i]>arr[i-1])
            dp[i] = dp[i-1]+1;
        else
            dp[i]=1;
        
    }
    //considering right wali condition
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>arr[i+1]&&dp[i]<=dp[i+1])
            dp[i]=dp[i+1]+1;
    }
        
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        //cout<<dp[i]<<" ";
        ans+=dp[i];
    }
    //cout<<endl;
    return ans;
}

