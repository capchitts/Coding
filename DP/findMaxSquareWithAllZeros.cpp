#include <bits/stdc++.h>
using namespace std;
/*
* TC ---> O(row*col)
* SC ---> O(row*col)
*/
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
	int **dp = new int*[row+1];
    
    for(int i=0;i<=row;i++)
    {
        dp[i] = new int[col+1];
        for(int j = 0;j<=col;j++)
            dp[i][j] = 0;
    }
    
    int max_ = 0;
    //dp[i][j] represent largest possible square matrix with i rows and j col encountered so far
    for(int i = 1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
        
            if(arr[i-1][j-1]==0)
                dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            
            if(dp[i][j]>max_)
                max_ = dp[i][j];
        }
    }
    
    delete [] dp;
    return max_;

}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}
