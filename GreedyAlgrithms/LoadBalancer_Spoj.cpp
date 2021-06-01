#include<bits/stdc++.h>
using namespace std;

//end not inclusive in calculation
int v_sum(vector<int> v,int s, int e)
{
	int res = 0;
	for(int i = s;i<e;i++)
	{
		res += v.at(i);
	}	
	
	return res;
}
int main()
{
	int n;
	int sum = 0;
	cin>>n;
	vector<int> v;
	
	for(int i = 0;i<n;i++)
	{
		int curr;
		cin>>curr;
		sum+=curr;
		v.push_back(curr);
	}
	//cout<<sum<<endl;
	//Check if equal distribution possibleor not
	if(sum%n != 0)
	{
		//cout<<"returning"<<endl;
		return -1;
	}
	
	
	/*find the max flow of jobs from one part of array to other part
	for all possible combinations
	*/
	int bal_factor = sum/n;
	int ans = INT_MIN;
	for(int i=1;i<=n-1;i++)
	{
		//array sum for both parts
		int f_sum = v_sum(v,0,i);
		int s_sum = v_sum(v,i,n);
		
		//balanced sum for both parts
		int f_fact = bal_factor*(i-0);
		int s_fact = bal_factor*(n-i);
		
		//find the direction of flow
		if(f_sum > f_fact)
		{
			ans = max(ans,f_sum - f_fact);
		}
		else
		{
			ans = max(ans,s_sum - s_fact);
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
