#include<bits/stdc++.h>
using namespace std;

int buyTicket(int *arr, int n, int k) {
    // Write your code here
    
    // Queue for maintaining the index
    queue<int> q;
    priority_queue<int> pq;
    
    for(int i = 0;i<n;i++)
    {
        
        q.push(i);
        pq.push(arr[i]);
            
    }
    
    //Pop till kth index element is not at top
    int res = 1;
    
    while(true)
    {
        int curr_per = arr[q.front()];
        
        if(q.front() == k && pq.top() == arr[k])
        {
            break;
        }
        
        if(pq.top() == curr_per)
        {
            res++;
            pq.pop();
            q.pop();
        }
        
        else
        {
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
        
       
        
    }
    
    return res;
}


int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}
