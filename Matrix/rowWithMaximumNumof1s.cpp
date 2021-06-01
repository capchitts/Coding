#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v,int l,int h)
{
        int med;
        int ind = -1;
        while(l<=h)
        {
            med = (l+h)/2;
            if(v[med]==0)
            {
                ind = med;
                l = med+1;
                binarySearch(v,l,h);
            }
            else
            {
                h = med-1;
                binarySearch(v,l,h);
            }
           
        }
        return v.size() -(ind+1);
}

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	// code here
	int count_max_so_far = 0;
	int res = 0;
	//O(mlog(n))
	for(int i = 0;i<arr.size();i++)
	{
	    int curr = binarySearch(arr[i],0,arr[i].size());
	    cout<<"Matrix's row i: "<<i<<" have "<<curr<<" num of 1s."<<endl;
	    if(count_max_so_far < curr)
	    {	
	    	res = i;
	    	count_max_so_far = curr;
	    }
	         
	}
	    
	return res;
	 
}



int main()
{
	vector<vector<int>> matrix = {{0, 0}, {1, 1}};
           
	int n = matrix.size(),m = matrix[0].size();
	int res = rowWithMax1s(matrix,n,m);
	cout<<"Result is : "<<res<<endl;
}
