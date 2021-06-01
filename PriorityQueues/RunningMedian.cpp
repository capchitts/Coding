#include<queue>
#include<vector>
using namespace std;

vector<int> sortedArray(priority_queue<int,vector<int>,greater<int>> pq)
{
    vector<int> res;
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    
    return res;
}

int median(vector<int> v)
{
    int s = v.size();
    if(s%2==0)
    {
        return (v.at((s -1)/2) + v.at(s/2))/2 ;
    }
    else
        return v.at(s/2);
}
void printRunningMedian(int *arr, int n) {
    // Write your code here
	priority_queue<int, vector<int>,greater<int>> pq;
    vector<int> s_vec;
    
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    	s_vec = sortedArray(pq);
        cout<<median(s_vec)<<" ";
    }
    cout<<endl;
}


int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    printRunningMedian(arr, n);

    delete[] arr;
}
