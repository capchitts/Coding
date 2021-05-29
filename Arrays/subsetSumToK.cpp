/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

using namespace std;
int subsetSumToK(int input[], int n, int si, int output[][50], int k) {
  if(si==n)
  {
    
     if(k==0)
     {
      output[0][0]=0;
      return 1;  
     }
      else
      {
      return 0;
      }
  }
  
  //small output step
  int s1,s2;
  int o1[1000][50];
  int o2[1000][50];
  
  //not including the current element
  s1 = subsetSumToK(input,n,si+1,o1,k);
  //including the current element
  s2 = subsetSumToK(input,n,si+1,o2,k-input[si]);
  
  int row=0;
  
  // saving in final output array 
  for(int i=0;i<s1;i++)
  {
    for(int j=0;j<=o1[i][0];j++)
    {
      //Oth element is the nimber of element in the subset
      output[row][j]=o1[i][j];
    }
    row++;
  }
    
  for(int i=0;i<s2;i++)
  {
    output[row][0]=o2[i][0]+1;
    output[row][1]=input[si];
      
    for(int j=1;j<=o2[i][0];j++)
    {
      output[row][j+1]=o2[i][j];
    }
    row++;
  }
  return row;
}


int subsetSumToK(int input[], int n, int output[][50], int k) {
  int j = 0;
  return subsetSumToK(input,n,j,output,k);
}

