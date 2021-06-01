#include <bits/stdc++.h>
using namespace std;

bool helper(int arr[],int n, int sum)
{
	int c_sum = 0;
	for(int i = 0;i<n;i++)
	{
		if(c_sum+arr[i] <=sum)
			c_sum += arr[i];
	}
	
	if(c_sum == sum)
		return true;
	
	return false;
}

bool equalsumpartition(int arr[],int n)
{
	int sum = 0;
	for(int i = 0;i<n;i++)
	{
		sum+=arr[i];
	}
	
	if(sum%2==0)
		return helper(arr,n,sum/2);
	
	return false;
}


int main()
{
	int arr[] = {1,5,11,4};
	
	int n = 4;
	
	cout<<endl;
	
	if(equalsumpartition(arr,n))
		cout<<"Yes , there exist equal sum partition."<<endl;
	else
		cout<<"No , there does not exist equal sum partition."<<endl;
	
	
	return 0;
}
