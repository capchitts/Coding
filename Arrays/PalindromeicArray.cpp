#include <bits/stdc++.h>
using namespace std;
/*Complete the function below*/

bool helper(int n)
{
    int k = n;
    int new_n = 0;
    while(k>0)
    {
        new_n = new_n*10 + k%10;
        k/=10;
    }
    
    if(new_n==n)
        return true;
       
    return false;
}

int PalinArray(int arr[], int n)
{  //add code here.
    for(int i=0;i<n;i++)
    {
        if(!helper(arr[i]))
            return 0;
    }
    return 1;
}

int main()
{
	int arr[] = {121 ,131 ,20};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout<<PalinArray(arr,n)<<endl;
	
	return 0;
}
