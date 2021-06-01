#include <bits/stdc++.h>
using namespace std;

void remMid(stack<int>& s, int n,int ind)
{
	if(n==1)
		return;
	if(n/2 == ind )
	{
		int rem = s.top();
		s.pop();
		cout<<"Element removed is: "<<rem<<endl;
		return;
	}
	
	int ele = s.top();
	s.pop();
	
	remMid(s,n,ind+1);
	
	s.push(ele);
	
} 

int main()
{
	stack<int> s;
	int n;
	cin>>n;
	cout<<endl;
	for(int i = 1;i<=n;i++)
	{
		s.push(i);
	}
	
	remMid(s,n,0);
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	
	cout<<endl;
	return 1;
}
