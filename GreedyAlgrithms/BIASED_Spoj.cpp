#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string, int>p1, pair<string, int> p2)
{
	return p1.second < p2.second;
}

int main()
{
	int t ,n ,r;
	string name;
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<pair<string,int>> v;
		
		for(int i = 0;i<n;i++)
		{
			cin>>name;
			cin>>r;
			
			v.push_back(make_pair(name,r));
		}
		
		//sort the vector
		sort(v.begin(),v.end(),compare);
		
		int ans=0;
		
		for(int i=1;i<=n;i++)
		{
			ans += abs(v[i-1].second - i);
		}
		
		cout<<endl<<ans;
		
		//clear after every test case
		v.clear();
	}
	cout<<endl;
	return 0;
}
