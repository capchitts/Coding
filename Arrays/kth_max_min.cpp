#include<bits/stdc++.h>
using namespace std;


// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    int min_ind =l;
    int max_ind = r;

    int maxx = INT_MIN;
    int minn = INT_MAX;
   
    while(l < r)
    {
        
        for(int i=l;i<=r;i++)
        {
            if(arr[i] < minn)
            {
                minn = arr[i];
                min_ind = i;
            }

            if(arr[i] > maxx)
            {
                maxx =arr[i];
                max_ind =i;
            }
        }
        int temp = arr[l];
        arr[l] = arr[min_ind];
        arr[min_ind] = temp;

        temp = arr[r];
        arr[r] = arr[max_ind];
        arr[max_ind] = temp;

        l++;
        r--;
    }
    
    
    return arr[k];    
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;

}