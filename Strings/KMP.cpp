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

bool kmp(string text, string pattern)
{
	int textLen = text.length();
	int PattLen = pattern.length();
	
	int i = 0,j=0;
	int *lps = getlps(pattern);
	
	while(i<textLen && j<PattLen)
	{
		//if pattern matching then increment both i and j
		if(text[i] ==pattern[j])
		{
			i++;
			j++;
		}
		
		else
		{
			if(j!=0)
				j = lps[j-1];
			
			else
			{
				i++;
			}
		}
		
		if(j==PattLen)
		{
			cout<<"Pattern found at index "<<i-j<<endl;
		}
	}
	
	if(j==PattLen)
		return true;
	
	return false;
}

int main()
{
	string text = "abcxabcdabcdabcy";
	string pattern = "aabaabaaa";
	
	bool ans = kmp(text,pattern);
	if(ans)
		cout<<"Match found"<<endl;
	else
		cout<<"Match not found"<<endl;
		
	int *arr = getlps(pattern);
	
	cout<<endl;
	
	for(int i =0;i<pattern.length();i++)
		cout<<arr[i]<<" ";
			
	return 0;
}
