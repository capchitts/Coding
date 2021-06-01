/*
Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.

*/

#include<bits/stdc++.h>
using namespace std;

int countPalindromeSubstrings(char s[])
{   
    int n = strlen(s);
    int mmax = 0;
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        //Odd length
		int l = i,r=i;
        while(l>=0 && r<n && s[l]==s[r])
        {
            
            count++;
            l--;
            r++;
        }
        
        //Even length
        l = i,r=i+1;
        while(l>=0 && r<n && s[l]==s[r])
        {
            
            count++;
            l--;
            r++;
        }
        
    }
    
    return count;
}

