#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> subsets(int input[], int n)
{
	int tot = pow(2,n);
	
	vector<vector<int>> res;
	
	for(int i = 0;i<tot;i++)
	{
		vector<int> v;
		for(int j = 0; j < n;j++)
		{
			if(i & (1<<j))
				v.push_back(input[j]);
				
				
		}
		res.push_back(v);
		v.clear();
	}
	
	return res;
}
int main()
{
	int input[] = {15 ,20 ,12};
	
	vector<vector<int>> res = subsets(input,3);
	vector<vector<int>> :: iterator itr;
	
	for(itr = res.begin();itr!=res.end();itr++)
	{
		vector<int> curr = *itr;
		vector<int> :: iterator itr_in;
		
		for(itr_in = curr.begin();itr_in != curr.end();itr_in++)
		{
			cout<<*itr_in<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
