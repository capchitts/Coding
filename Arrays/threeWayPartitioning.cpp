#include <bits/stdc++.h>
using namespace std;

void threeWayPartition(int *array,int n, int a, int b)
{
        // code here 
        int s = 0, e = n-1;
        int i = 0;
        
        while(i<=e)
        {
            /*current ele less than a
            * then swap curr ele with 
            * next starting position
            */
            if(array[i]<a)
            {
                swap(array[i++],array[s++]);
            }
            
            /*current ele greater than b
            * then swap curr ele with 
            * next ending position
            */
            else if(array[i]>b)
            {
            	/*here i is not incremented because need to check again 
            	*+555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555on the element which is swapped back here
               */
                swap(array[i],array[e--]);
            }
            
            else
                i++;
        }
        
}

int main()
{
	int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
	int n = sizeof(arr)/sizeof(arr[0]);
	int a = 10;
	int b = 20;
	
	threeWayPartition(arr,n,a,b);
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
}