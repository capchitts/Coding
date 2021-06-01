#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> v,int l , int h, int target)
    {
        
        int med;
        
        while(l<=h)
        {
            med = (h+l)/2;
            if(v[med]==target)
                return true;
            else if(target > v[med])
            {
                l = med+1;
                
                binarySearch(v,l,h,target);
            }
            else
            {
                h = med-1;
                binarySearch(v,l,h,target);
            }
        }
        
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        
        //find the inner vector
        for(int i = 0;i<m;i++)
        {
            int s = matrix[i].size();
            if(target >= matrix[i][0] && target <=matrix[i][s-1])
            {
                int l = 0;
                int h = s-1;
                return binarySearch(matrix[i],l,h,target);
            }
        }
        return false;
    }

int main()
{
	vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
	int target = 11;
	(searchMatrix(matrix,target))?cout<<"yes"<<endl:cout<<"no"<<endl;
	return 1;
	
}
