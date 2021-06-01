#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,d;
	cin>>n>>d;
	vector<int> v;
	for(int i = 0;i<n;i++)
	{
		int ele;
		cin>>ele;
		v.push_back(ele);
	}
	
	//greedy steps
	sort(v.begin(),v.end());
	int res = 0;
	
	for(int i=1;i<n;i++)
	{
		if(v[i] - v[i-1] <= d)
		{
			res++;
			i+=1;
		}
	}
	cout<<endl<<res<<endl;
	return 0;
}
