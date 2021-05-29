//optimal strategy of time complexity O(nlogn+mlogm) and space complexity O(1)
int nextgap(int n)
    {
        if(n<=1)
            return 0;
        //take care fo returning the gap value correct when n is odd;
        return (n/2)+(n%2);
    }
void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    
	    //form bitonic arrays of given arrays
	    int x  = min(n,m);
	    
	    for(int i=0;i<x;i++)
	    {   
	        //compare from last element of arr1 with start element of array2
	        if(arr1[n-i-1] > arr2[i])
	        {
	            swap(arr1[n-i-1],arr2[i]);
	        }
	        
	    }
	    
	    //apply gap method on array1
	    //int gap = n/2; this gap initialization will cause gap to miss some values when size is odd
	    for(int gap = nextgap(n);gap>0;gap=nextgap(gap))
	    {
	        for(int i = 0;i+gap<n;i++)
	        {
	  
	            if(arr1[i]>arr1[i+gap])
	                swap(arr1[i],arr1[i+gap]);
	           
	        }
	    }
	    
	    //apply gap method on array2
	    for(int gap = nextgap(m);gap>0;gap=nextgap(gap))
	    {
	        
	        for(int i = 0;i+gap<m;i++)
	        {
	                
	            if(arr2[i]>arr2[i+gap])
	                swap(arr2[i],arr2[i+gap]);
	           
	           
	        }
	    }
}
