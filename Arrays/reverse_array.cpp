#include <bits/stdc++.h>
using namespace std;

/*
Given an array (or string), the task is to reverse the array/string.
*/

void reverse_array(int arr[],int n)
{

    int e_ind = n-1;
    for(int i = 0;i<n/2;i++)
    {
        int temp = arr[i];
        arr[i] = arr[e_ind];
        arr[e_ind] = temp;
        e_ind -=1;
    }

}

void print_array(int *arr, int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    reverse_array(arr,5);
    /*
    for(int i = 0;i<5;i++)
    {
    	cout<<res[i]<<" ";
    }
    cout<<endl;
    */
    print_array(arr,5);

    return 0;
}