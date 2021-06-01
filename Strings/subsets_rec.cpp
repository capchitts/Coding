#include <bits/stdc++.h>
using namespace std;

void subset(string inp, int n, int ind, string curr)
{
	if(ind == n-1)
	{
		cout<<curr<<endl;
		return;
	}
	//choices
	//1.Choosing current element
	subset(inp,n,ind+1,curr+inp[ind+1]);
	//2. Not choosing current element
	subset(inp,n,ind+1,curr);
	
	return;
}
int main()
{
	string inp ="abc";
	int n = inp.length(); 
	subset(inp, n, -1,"");
	return 0;
}
