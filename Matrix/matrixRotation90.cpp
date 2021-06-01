/*
*
*/

#include<bits/stdc++.h>
using namespace std;


void transpose(vector<vector<int>> &matrix,int r, int c)
{
	
	for(int i = 0;i<r;i++)
	{
		for(int j = i;j<c;j++)
		{

			swap(matrix[i][j],matrix[j][i]);
		}
	}
}

void rowSwap(vector<vector<int>> &matrix,int r, int c)
{
	for(int i=0;i<r/2;i++)
	{
		for(int j = 0;j<c;j++)
		{
			swap(matrix[i][j],matrix[r-1-i][j]);
		}
	}
}

void print_matrix(vector<vector<int>> &matrix,int r, int c)
{
	for(int i = 0;i<r;i++)
	{
		for(int j = 0;j<c;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

void rotate(vector<vector<int>> &matrix,int r, int c)
{
	transpose(matrix,r,c);
	rowSwap(matrix,r,c);	
}

int main()
{

	vector<vector<int>> matrix = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 }};
        int r = matrix.size();
        int c = matrix[0].size();
       
	cout<<"Before rotation: "<<endl;
	print_matrix(matrix,r,c);
	cout<<"After rotation: "<<endl;
	rotate(matrix,r,c);
	//transpose(matrix,r,c);
	//rowSwap(matrix,r,c);
	print_matrix(matrix,r,c);
	
	return 0;
	
}
