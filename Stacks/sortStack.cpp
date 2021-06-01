#include <bits/stdc++.h>
using namespace std;


void insert(stack<int> &s, int ele)
{
	if(s.empty() || s.top() <= ele)
	{	
		s.push(ele);
		return;
	}
	//otherwise need to pop last value from stack and insert the ele in remaining stack
	int val = s.top();
	s.pop();
	insert(s,ele);
	insert(s,val);
	
	
}

void sortStack(stack<int> &s)
{
		if(s.size() == 1)
		{	
			return;
		}
		
		int ele = s.top();
		s.pop();
		insert(s,ele);
		

}
	
int main()
{
	int n;
	cin>>n;
	stack<int> s;
	int ele = 0;
	while(n>0)
	{
		cin>>ele;
		s.push(ele);
		n--;
	}
	
	sortStack(s);
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	return 1;
}
