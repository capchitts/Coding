#include <iostream>
using namespace std;


int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	//Write your code here
    int **dp = new int*[numDenominations+1];
    
    for(int i=0;i<=numDenominations;i++)
    {
        dp[i] = new int[value+1];
        for(int j = 0;j<=value;j++)
        {
            //sum of zero with every size is possible by excluding it
            if(j==0)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
            
    }
    
    for(int i = 1;i<=numDenominations;i++)
    {
        for(int j = 1;j<=value;j++)
        {
            if(denominations[i-1] <= j)
                dp[i][j] = dp[i][j-denominations[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[numDenominations][value];
    
    
}


int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}
