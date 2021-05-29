/*
res = max(max_left_height,max_right_height) - arr[i] , keep in mind i start from 1
----1----> O(n2) approach is to find max on both side of index i and then find res
----2---->O(n) approach O(1) space ,  
*/
#include<bits/stdc++.h>
using namespace std;

int trapRainWater(int *arr, int n)
{
	int left_max = 0, right_max = 0;
	int left = 0, right = n-1;
	int res = 0;
	while(left < right)
	{
		//if left is less than  trapping constraints are from left , so look in its left and update res if left_max is freater than arr[left[
		if(arr[left] < arr[right])//
		{
			if(arr[left] < left_max)
			{
				res+= left_max - arr[left];
			}
			else//update left_max
			{
				left_max = arr[left];
			}
			left++;
		}
		
		else
		{
			if(arr[right] < right_max)
			{
				res+= right_max - arr[right];
			}
			else
			{	
				right_max = arr[right];
			}
			right--;
		}
	}
	
	return res;
}

int main()
{
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<trapRainWater(arr,n)<<endl;
}
