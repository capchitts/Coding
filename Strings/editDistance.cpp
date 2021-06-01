#include <bits/stdc++.h>
using namespace std;

int editDistance(string s, string t)
{
	int m = s.length();
	int n = t.length();
	int dp[m+1][n+1];
        
        memset(dp,0, sizeof dp);   
	//initialization of Boundary cases
	//1->s is empty string i.e  0th index row
	for(int i = 0;i<=n;i++)
	{
		dp[0][i] = i;
	}
		    
	//2->s is empty string i.e oth index col
	for(int j = 0;j<=m;j++)
	{
		dp[j][0] = j;	
	}
		    
	for(int i = 1;i<=m;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			// curr chars are same
		      	if(s[i-1] == t[j-1])
		        	dp[i][j] = dp[i-1][j-1];
		                
		        else
		        {
				dp[i][j] = 1 + min(dp[i][j - 1], // Insert 
						min(dp[i - 1][j], // Remove 
						dp[i - 1][j - 1])); // Replace 
		        }
		}
        }
        
        return dp[m][n];
		    
}

int main()
{
	string s = "sunday";
	string t = "saturday";
	
	cout<<editDistance(s,t)<<endl;
	
	s = "food";
	t = "money";
	cout<<editDistance(s,t)<<endl;
	
	s = "abc";
	t = "bcd";
	cout<<editDistance(s,t)<<endl;
	return 0;
}
