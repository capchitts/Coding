// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void sort012(int[],int);

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

// } Driver Code Ends


void sort012(int arr[], int n)
{
    // coode here 
    int count_t = 0, count_o = 0,count_z =0;
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i]==1)
            count_o +=1;
            
        sum+=arr[i];
        arr[i] = 0;
    }
    
    count_t = (sum - count_o)/2;
    count_z = n - count_o - count_t;
    
    for(int i = n-count_t;i<n;i++)
    {
        arr[i] = 2;
    }
    for(int i=count_z;i<n-count_t;i++)
    {
        arr[i] = 1;
    }
}
