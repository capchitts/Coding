#include<bits/stdc++.h>
using namespace std;

/*
Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.

For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-  10 = 1^2 + 3^2
Sample Input 2 :
100 2
Sample Output 2 :
3
Explanation:
Following are the three ways: 
1. 100 = 10^2
2. 100 = 8^2 + 6^2
3. 100 = 7^2+5^2+4^2+3^2+1^2 
*/

int countSubsetSum(vector<int> vec, int sum)
{
    int n = vec.size();
    int dp[n + 1][sum + 1]; 
  
    
    for (int i = 0; i <= n; i++) 
        dp[i][0] = 1; 
  
  
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = 0; 
  
    // Fill the subset table in botton up manner 
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
             
             if (j >= vec[i - 1]) 
                //sum till previous size array + including this element from array
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - vec[i - 1]];
                
             else
                //sum till previous size of array
             	dp[i][j] = dp[i - 1][j];  
        } 
    } 
     /*
     cout<<endl;
     for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= sum; j++) 
          printf ("%4d", dp[i][j]); 
       printf("\n"); 
     }
    */
    return dp[n][sum]; 
}

int getAllWays(int a, int b) {
	// Write your code here
	
    /*Can  be solve by using Count Subset Sum by making the SUM = a and creating a vector with desired elements
      a = 10 , b = 2 , vec - <1, 4, 9> for elements 1, 2, 3 , only these elements raise to power b can result in sum == 10
      a = 100, b = 3 , vec - <1, 8, 27, 64> for elemenst 1, 2,3,4 , now find subsetSumCount==100
    */
    int i = 1;
    //To store the array to use for making sum equal to a
    vector<int> vec;
    while(pow(i,b)<=a)
    {
        vec.push_back(pow(i,b));
        i++;
    }
    return countSubsetSum(vec, a);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}
