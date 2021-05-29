#include<bits/stdc++.h>
using namespace std;



void one_side_neg_no_order(int arr[],int n) {
    int s_ptr = 0, e_ptr = n-1;
    while(s_ptr < e_ptr)
    {
    	if(arr[s_ptr] >0 && arr[e_ptr]<0)
    	{
    		int temp = arr[s_ptr];
    		arr[s_ptr] = arr[e_ptr];
    		arr[e_ptr] = temp;
    		s_ptr++;
    		e_ptr--;
    		
    	}
    	else if(arr[s_ptr] >0)
    	{	
    		e_ptr--;
    	}
    	else if(arr[e_ptr] < 0)
    	{
    		s_ptr++;
    	}
    	else
    	{
    	//both are at right position
    		s_ptr++;
    		e_ptr--;
    	}
    }
    
    
}
//insertion sort modification
void with_order(int arr[],int n)
{
	int f_pos = -1;
	int i = 0;
	while(i<n)
	{
		//first positive element
		if(f_pos==-1 && arr[i] >0)
		{
			f_pos = i;

		}
		//positive element present before ith negative element
		else if(f_pos != -1 && arr[i] < 0)
		{
			int temp = arr[i];
			//maximum can be of O(n)
			for(int j =i-1;j >= f_pos;j--)
			{
				arr[j+1] = arr[j];
				
			}
			arr[f_pos] = temp;
			f_pos = f_pos+1;

		}
		i++;
	}
}

int main()
{
    
        int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
    	int n = sizeof(arr) / sizeof(arr[0]);

        
        //one_side_neg_no_order(arr,n);
        with_order(arr,n);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    
    	return 0;

}
