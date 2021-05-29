#include <bits/stdc++.h>
using namespace std;

int minDifference(int *arr, int n, int k)
{
	sort(arr,arr+n);
	int minn = INT_MAX;
	//find the max - min difference in window of k elements
	for(int i=0;i<=n-k;i++)
	{
		if(arr[i+k-1] - arr[i] < minn)
			minn = arr[i+k-1] - arr[i];
	}
	
	
	return minn;
}


/*
Given an array A[] consisting of N integers, where each value represents the marks of the ith student, the task is to find the minimum number of chocolates required to be distributed such that:

Each student should be awarded with at least one chocolate
A student with higher marks should be awarded more chocolates than his adjacent students.
*/
int chocDistributionBasedOnMarks(int *arr,int n)
{
	int b[n];
	for(int i=0;i<n;i++)
	{
		b[i] = 1;
	}
	//update ith student chocolate share for any student having less marks than ith student in i-1th location. 
	for(int i=1;i<n;i++)
	{
		if(arr[i] > arr[i-1])
			b[i] = b[i-1]+1;
		else
			b[i] = 1;
	}
	//update ith student chocolate share for any student having less marks than ith student in i+1th location. 
	for(int i = n-2;i>=0;i--)
	{
		if(arr[i]>arr[i+1])
			b[i] = max(b[i],b[i+1]+1);
		else
			b[i] = max(b[i],1);
	}
	
	int res = 0;
	for(int i = 0;i<n;i++)
	{
		res+=b[i];
	}
	
	return res;
}
int main()
{
	/*
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int k;
		cin>>k;
		
		cout<<minDifference(arr,n,k)<<endl;
	}
	*/
	int arr[] = {23, 14, 15, 14, 56, 29, 14};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<chocDistributionBasedOnMarks(arr,n)<<endl;
	return 0;
	
}
