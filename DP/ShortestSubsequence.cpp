/*
*Shortest Subsequence
Send Feedback
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
Input Format :
The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Constraints:
1 <= N <= 1000
1 <= M <= 1000 
Time Limit: 1 second
Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.
*/


#include<bits/stdc++.h>
using namespace std;

#define MAX 1005

int solve(string S,string T)
{
    // Write your code here.
    int m = S.length(), n = T.length();
    
    // declaring 2D array of m + 1 rows and
    // n + 1 columns dynamically
    int dp[m+1][n+1];
    
    // T string is empty
    for (int i = 0; i <= m; i++)
    	dp[i][0] = 1;
    
    // S string is empty
    for (int i = 0; i <= n; i++)
    	dp[0][i] = MAX;
    
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch = S[i-1];
            int k;
            for (k = j-1; k >= 0; k--)
                if (T[k] == ch)
                    break;
            // char not present in T
            if (k == -1)
                dp[i][j] = 1;
            else
                dp[i][j] = min(dp[i-1][j], dp[i-1][k] + 1);
        }
    }
    int ans = dp[m][n];
    
    if (ans >= MAX)
    	ans = -1;
    return ans;
}


int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}
