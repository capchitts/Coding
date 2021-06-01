#include <queue>
#include<vector>
using  namespace std;

vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
	priority_queue<int> pq;
    vector<int> res;
    
    for(int i = 0;i<n;i++)
    {
        pq.push(-1*arr[i]);
    }
    
    for(int i=0;i<k;i++)
    {
    	res.push_back(-1*pq.top());
        pq.pop();
    }
    
    return res;

}

vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
	priority_queue<int> pq;
    vector<int> res;
    
    for(int i = 0;i<n;i++)
    {
        pq.push(-1*arr[i]);
    }
    
    for(int i=0;i<k;i++)
    {
    	res.push_back(-1*pq.top());
        pq.pop();
    }
    
    return res;

}
