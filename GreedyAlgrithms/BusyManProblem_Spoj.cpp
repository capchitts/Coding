#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1 , pair<int,int> p2)
{
	return p1.second < p2.second;
}

int main()
{
	int t, n, s, e;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		vector<pair<int,int>> v;
		
		for(int i = 0;i<n;i++)
		{
			cin>>s>>e;
			v.push_back(make_pair(s,e));
		}
		
		cout<<endl;
		//Activity Selection
		//sort
		sort(v.begin(),v.end(),compare);
		
		//Start picking activites
		int res = 1;
		int fin = v[0].second;
		
		//iterate over remaining activites
		for(int i=1;i<n;i++)
		{
			/*next activity is only chosen 
			if its starting time is greaater 
			than equal to prev fin time*/
			if(fin <= v[i].first)
			{
				res+=1;
				fin = v[i].second;
			}
		}
		
		cout<<"Number of activites he can do are: "<<res<<endl;
		
		//clear vector after each test case
		v.clear();
	}
}
