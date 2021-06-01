/*
*I will assume that the next is the input of the problem:

A set of non-negative numbers {w1,w2,…,wn} - weights
A set of numbers {v1,v2,…,vn} - values
A non-negative value W - available volume
We want to solve something like
				max (i∑i=1 to n)λivi
				s.t.∑i=1 to n λiwi ≤ W

There are exactly 2n subsets, and in the trivial solution we will check them all!

For i∈{0,1,…,2n−1} look at the binary representation of i and take the objects accordingly, i.e. if bit bj−1 (counted from right to left) at position j−1 is set (=1) take the object j to your bag. If the total weight of the subset i (i.e. all the taken objects) weighs less than W, record the weight of the subset. If it is less than previous record - update the record. You can forget the weight now !!!

E.g. for i=13410=100001102 you take objects indexed by 2,3,8 to the subset and do not take anything else.
*/

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
    //Base Case
    if(n == 0 || maxWeight == 0)
        return 0;
    
    //Decision
    if(weights[n-1] <= maxWeight)
    {
        return max(values[n-1]+knapsack(weights, values, n-1 , maxWeight - weights[n-1]),
                  knapsack(weights , values , n-1 , maxWeight));
    }
    
    else
        return knapsack(weights, values,n-1,maxWeight);
}

/*
*Complexity Analysis: 

Time Complexity: O(n*maxWeight). 
As redundant calculations of states are avoided.
Auxiliary Space: O(n*maxWeight). 
The use of 2D array data structure for storing intermediate states-:
*/


int knapsack_Mem(int *weights, int *values, int n, int maxWeight, int **dp)
{
	//write your code here
    //Base Case
    if(n == 0 || maxWeight == 0)
        return 0;
    
    
    //if already present
    if(dp[n][maxWeight] != -1)
    	return dp[n][maxWeight];
    
    //Decision
    if(weights[n-1] <= maxWeight)
    {
        
        dp[n][maxWeight] = max(values[n-1]+knapsack_Mem(weights, values, n-1 , maxWeight - weights[n-1],dp),
                  knapsack_Mem(weights , values , n-1 , maxWeight,dp));
    }
    
    else
        dp[n][maxWeight] =  knapsack_Mem(weights, values,n-1,maxWeight,dp);
    
    return dp[n][maxWeight];
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    
    int **dp = new int*[n+1];
    
    for(int i = 0;i<=n;i++)
    {
        dp[i] = new int[maxWeight+1];
        for(int j = 0;j<=maxWeight;j++)
            dp[i][j] = -1;
    }
    
    
    return knapsack_Mem(weight, value, n, maxWeight,dp);
    
}
