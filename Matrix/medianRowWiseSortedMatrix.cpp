/*
*Time Complexity: O(32 * r * log(c)). The upper bound function will take log(c) time and is performed for each row. 
*And since the numbers will be max of 32 bit, so binary search of numbers from min to max will be performed in at most 32 ( log2(2^32) = 32 ) operations. 
*Auxiliary Space : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>> matrix, int r, int c)
{
	int min = INT_MAX, max = INT_MIN;
	//find min and max from elements of 1st col and last col respectively
	for(int i=0;i<r;i++)
	{
		if(matrix[i][0]<min)
			min = matrix[i][0];
		
		if(matrix[i][c-1]>max)
			max = matrix[i][c-1];
		
	}
	
	//number of values a median should be greater than
	int thresh = (r*c+1)/2;
	
	//applying binary search
	while(min < max)
	{
		int mid = min +(max-min)/2;	
		//count number of elements less than current mid value
		int count = 0;
		for(int i=0;i<r;i++)
		{
			/*
			for(int j=0;j<c;j++)
			{
				if(mid >= matrix[i][j])
					count++;
			}
			*/
			//https://www.geeksforgeeks.org/upper_bound-in-cpp/
			count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
		}
		
		cout<<"min, max,  mid value: "<<min<<" "<<max<<" "<<mid<<" count is: "<<count<<endl;
		//it means mid should be greater than current mid
	
		if(count < thresh)
		{
			min = mid+1;
		}	
		else
		{
			max = mid;
		}
	}
	
	return min;	
}

int main()
{
	vector<vector<int>> matrix = { {1,3,5}, {2,6,9}, {3,6,9} };
	
	cout<<findMedian(matrix,matrix.size(),matrix[0].size())<<endl;
	return 0;
}

