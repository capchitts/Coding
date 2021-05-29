#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
{
  //Your code here
  int maxx = 0;
  unordered_set<int> s;
  
  
  for(int i=0;i<N;i++)
  {
      s.insert(arr[i]);
    
  }
  
  for(int i=0;i<N;i++)
  {
      //means current element is the first element for sequence
      if(s.find(arr[i]-1) == s.end())
      {
          
          int j = arr[i];
          while(s.find(j)!= s.end())
          {
              j++;
              cout<<"j: "<<j<<endl;
          }
          //series started from arr[i]
          maxx = (maxx > j-arr[i])?maxx:j-arr[i];
          
      }
      //else traverse ahead for looking the first element of seqauence
  }
  
  return maxx;
}

int main()
{
	int arr[] = {1,9,3,10,4,20,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<findLongestConseqSubseq(arr,n)<<endl;
}
