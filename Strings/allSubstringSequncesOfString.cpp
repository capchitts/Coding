#include <bits/stdc++.h>
using namespace std;

void helper(string s, int n, vector<string> &res, int index = -1, string curr="")
{
	if(index == n)
	{
		return;
	}
		
	res.push_back(curr);
	cout<<curr<<endl;
	
	
	for(int i=index+1;i<n;i++)
	{
		//add index char to curr
		curr += s[i];
		
		helper(s,n,res,i,curr);
		
		//remove the previously added element
		curr = curr.erase(curr.size()-1);
	}
	
	
}

void stringSubsequences(string s, int n)
{	
	vector<string> res;
	
	helper(s,n,res,-1,"");
	
	cout<<"Number of substrings: "<<res.size()<<endl;
}

int main()
{
	string s;
	cin>>s;
	
	int n = s.length();
	
	stringSubsequences(s, n);
	return 0;
}

