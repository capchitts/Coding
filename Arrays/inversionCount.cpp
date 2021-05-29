#include <bits/stdc++.h>
using namespace std;

//O(n*n)
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    //long long s_arr[N+1];
    //copy(arr,arr+N,s_arr);
    //sort(s_arr,s_arr+N);
    
    long long int c_inv = 0;
    for(long long int i=1;i<N;i++)
    {
        for(long long int j=i-1;j>=0;j--)
        {
     
            if(arr[j]>arr[i])
            {
                c_inv+=1;
            }
            
        }
        
    }
    
    return c_inv;
}


int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

//orginial function to call
int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

//helper function
int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and 
        call _mergeSortAndCountInv() 
        for each of the parts */
        mid = (right + left) / 2;

        /* Inversion count will be sum of 
        inversions in left-part, right-part 
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}


/* This func merges two sorted arrays 
and returns inversion count in the arrays.*/
int merge(int arr[], int temp[], int left,int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) 
    {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        //element in left array greater than element in right array means inversion
        else {
            temp[k++] = arr[j++];

            //mid - i because the array will be sorted and the next elements will also be greater than this current element in right
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

//O(n*n) as distance takes O(n) time
int getInvCount(long long arr[],long long int N)
{
	multiset<long long int> m;
	m.insert(arr[0]);
	long long int inv = 0;
	
	multiset<long long int>::iterator itr;
	
	for(long long int i = 1;i<N;i++)
	{
		//insert the element in multiset, it makes the set sorted always using Red Black trees
		m.insert(arr[i]);
		
		//upperbound functions return the iterator pointing to the position of next larger element in set or set.end() if none is greater than it
		itr = m.upper_bound(arr[i]);
		
		inv += distance(itr,m.end());
		
	}
	
	return inv;
}

// Driver code
int main()
{
    long long arr[] = { 1, 20, 6, 4, 5 };
    long long int n = sizeof(arr) / sizeof(arr[0]);
    long long int ans = getInvCount(arr, n);
    cout << " Number of inversions are " << ans;
    return 0;
}


