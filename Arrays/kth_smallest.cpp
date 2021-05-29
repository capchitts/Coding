#include<bits/stdc++.h>
using namespace std;


int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    vector<int> vec(arr+0,arr+r+1);
    priority_queue<int> pq;
    
    int cap = k;
    //first only push k elements into it
    for(int i=0;i<k;i++)
    {
        
        pq.push(vec[i]);
        
    }
    
    for(int i = k;i<r+1;i++)
    {
        //because every insertion takes place O(log(n))
        if(vec[i] < pq.top())
        {
            pq.pop();
            pq.push(vec[i]);
        }
    }
    
    return pq.top();
}

int main()
{
    
        int n = 4;
        int a[] ={777 ,83 ,417 ,746};
        int k = 3;
        
        int ans  = kthSmallest(a, 0, n-1, k);
        
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
    
    	return 0;

}
