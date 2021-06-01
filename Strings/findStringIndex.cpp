// S and T - input strings
// You need to check if string T is present in S or not ,return startinf index if present else return -1;

#include <bits/stdc++.h>
using namespace std;


int* getlps(string pattern)
{
	
	int len = pattern.length();
	int* lps = new int[len];
	
	lps[0] = 0;
	int i = 1,j = 0;
	
	while(i<len)
	{
		if(pattern[i] == pattern[j])
		{
			lps[i] = j+1;
			i++;
			j++;
		}
		else
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	
	return lps;
		
}


int findString(char S[], char T[]) {
    // Write your code here
    string text = S;
    string pattern = T;
    
	int textLen = text.length();
	int PattLen = pattern.length();
	
	int i = 0,j=0;
    
	int *lps = getlps(pattern);
	
	while(i<textLen && j<PattLen)
	{
		if(text[i] ==pattern[j])
		{
			i++;
			j++;
		}
        
		else
		{
            //using the concept of Longest Prefix that is also suffix
			if(j!=0)
				j = lps[j-1];
			
			else
			{
				i++;
			}
		}
        
        if(j==PattLen)
        {
             return i-j;
        }
            
	}
	
	
	return -1;
}


