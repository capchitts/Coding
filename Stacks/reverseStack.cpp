#include <bits/stdc++.h>
using namespace std;

void revStackprint(stack<int> &s, int n)
{
	if(n == 1)
	{
		cout<<s.top()<<" ";
		return;
	}
	
	int ele = s.top();
	s.pop();
	revStackprint(s,n-1);
	cout<<ele<<" ";
	s.push(ele);
	
}

void insertAtLast(stack<int> &s,int ele)
{
	if(s.empty())
	{
		s.push(ele);
		return;
	}
	
	int cur = s.top();
	s.pop();
	
	insertAtLast(s,ele);
	
	s.push(cur);
		
}

void revStack(stack<int> &s)
{
	if(s.empty())
	{
		return;	
	}
	
	int el = s.top();
	s.pop();
	
	revStack(s);
	
	insertAtLast(s,el);
	
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
	
	
	//revStackprint(s,n);
	revStack(s);
	
	for(int i = 0;i<n;i++)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	return 0;
}
