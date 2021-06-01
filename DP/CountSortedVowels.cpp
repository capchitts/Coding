
/*1641. Count Sorted Vowel Strings
Medium

1010

26

Add to List

Share
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
Example 2:

Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
Example 3:

Input: n = 33
Output: 66045
*/

class Solution {
public:
    int sum_row(int **dp, int row, int s_col)
    {
        int ans = 0;
        for(int i=s_col;i<=4;i++)
        {
            ans += dp[row][i];
        }
        
        return ans;
    }
    int countVowelStrings(int n) {
    
        if(n==1)
            return 5;
        int **dp = new int*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i] = new int[5];
            for(int j = 0;j<5;j++)
            {
                dp[i][j] = 0;
            }
        }
        
        //Column 1 to 5 represent a,e,i,o,u resp
        // dp[i][j] represent number of strings of lenght i starting with char j
        
        //initialization , length 1 strings
        for(int i=0;i<5;i++)
        {
            dp[1][i] = 1;
        }
        
        for(int i=2;i<=n;i++)
        {
            for(int j = 0;j<5;j++)
            {
                dp[i][j] = sum_row(dp,i-1,j);
            }
        }
        
        int res = 0;
        for(int i = 0;i<5;i++)
        {
            res+=sum_row(dp,n-1,i);
        }
        
        for(int i = 0;i<-n;i++)
        {
            
            delete [] dp[i];
        }
        delete [] dp;
        
        return res;
    
    }
};
