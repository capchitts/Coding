/*
*TC --> O(3^(mn))
*SC --> O(max(m,n))
*/
int helper(int **input,int m,int n,int x,int y)
{
    if(x==m-1 && y==n-1)
        return input[x][y];
        
    if(y==n-1)
    {
        //can only go down
        return input[x][y] + helper(input,m,n,x+1,y);
    }
    if(x==m-1)
    {
        //can only go right
        return input[x][y] + helper(input,m,n,x,y+1);
    }
    
    int down = helper(input,m,n,x+1,y);
    int right = helper(input,m,n,x,y+1);
    int diag = helper(input,m,n,x+1,y+1);
    
    return input[x][y]+ min(min(down,right),diag);
}
int minCostPath(int **input, int m, int n)
{
	return helper(input,m,n,0,0);
}
