#include <bits/stdc++.h>
using namespace std;

int median(int *arr1, int m, int *arr2, int n)
{
	int l  = 0,r = 0;
	
	int med_ele = (m+n)/2;
	int res[m+n];
	int k = 0;
	
	while(l<m && r<n)
	{
		if(arr1[l]<=arr2[r])
		{	
			res[k] = arr1[l];
			l++;
		}
		else
		{
			res[k] = arr2[r];
			r++;
		}
		k++;
	}
	
	for(int i = l;i<m;i++)
	{
		res[k++] = arr1[i];
	}
	
	for(int i = r;i<n;i++)
	{
		res[k++] = arr2[i];
	}
	
	/*
	for(int i = 0;i<m+n;i++)
	{
		cout<<res[i]<<" ";
	}
	*/
	cout<<endl;
	
	if((m+n)%2==0)
	{
		return (res[med_ele-1]+res[med_ele])/2;
	}
	
	return res[med_ele];
	
}
int main()
{
	
	
	int arr1[] = {2, 3, 5, 8};
	int m = sizeof(arr1)/sizeof(arr1[0]);
	int arr2[] = {10, 12, 14, 16, 18, 20};
	int n = sizeof(arr2)/sizeof(arr2[0]);
	
	cout<<median(arr1,m,arr2,n)<<endl;
	return 0;
	
}
