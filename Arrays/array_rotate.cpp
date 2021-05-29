#include <bits/stdc++.h>
using namespace std;

void swap_array(int arr[], int left_start_ind, int right_start_ind,int num_of_ele_to_rot){
	
	int temp;
	
	for(int i=0;i<num_of_ele_to_rot;i++)
	{
		temp = arr[right_start_ind];
		arr[left_start_ind+i] = arr[right_start_ind+i];
		arr[right_start_ind+i] = temp;	
	}
}

void left_rotate(int arr[], int num_ele_to_rot, int arr_size){
	
	if(num_ele_to_rot == 0 || num_ele_to_rot==arr_size)
		return;
	
	if(num_ele_to_rot == arr_size - num_ele_to_rot)
	{
		//final block has reached at end of array
		swap_array(arr,0,arr_size - num_ele_to_rot,num_ele_to_rot);

	}
	
	//A<B
	if(num_ele_to_rot < arr_size )
	{
		//final block has reached at end of array
		swap_array(arr,0,arr_size - num_ele_to_rot,num_ele_to_rot);
		left_rotate(arr, num_ele_to_rot, arr_size-num_ele_to_rot);
	}
	//B<A
	if(num_ele_to_rot > arr_size - num_ele_to_rot)
	{
		//final block reached at starting of array
		swap_array(arr,0,num_ele_to_rot,arr_size - num_ele_to_rot);
		left_rotate(arr+(arr_size-num_ele_to_rot),2*num_ele_to_rot - arr_size,num_ele_to_rot);
	}
	
}

void reversal(int arr[], int s_i,int e_i)
{
		while(s_i<e_i)
		{
			int temp = arr[e_i];
			arr[e_i] = arr[s_i];
			arr[s_i] = temp;
			s_i++;
			e_i--;
		}
	
}

void left_rotate_reversal(int arr[],int d, int n)
{
	if(d==0)
	return;
	
	d = d%n;
	
	reversal(arr,0,d-1);
	reversal(arr,d,n-1);
	reversal(arr,0,n-1);
	
	return;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]); 
    left_rotate_reversal(arr, 5, n); 
    
    for(int i = 0;i<n;i++)
    {
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0; 
	
}
