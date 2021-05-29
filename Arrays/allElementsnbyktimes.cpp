#include <bits/stdc++.h>
using namespace std;

vector<int> getElements(int *arr,int n,int k)
{
	int thresh = n/k;
	vector<int> res;
	unordered_map<int,int> m;
	for(int i=0;i<n;i++)
	{
		m[arr[i]]+=1;
	}
	
	unordered_map<int,int> :: iterator itr;
	for(itr=m.begin();itr!=m.end();itr++)
	{
		if(itr->second > thresh)
		{	
			res.push_back(itr->first);
		}
	}
	
	return res;
	
}

int main()
{
	int arr[] = {3, 1, 2, 2, 1, 2, 3, 3} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 4;
	vector<int> res = getElements(arr,n,k);
	
	vector<int> ::iterator itr;
	for(itr = res.begin();itr!=res.end();itr++)
	{
		cout<<*itr<<" ";
	}
	cout<<endl;
}
