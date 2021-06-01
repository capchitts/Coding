#include <bits/stdc++.h>
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    unordered_map<int,int> m;
    
    int res = 0;
    
    for(int i=0;i<n;i++)
    {
    	if(m.count(arr[i] - k)>0 || m.count(arr[i] + k)>0)
        {
            res+=m[arr[i] - k]>0?m[arr[i]-k]:m[arr[i]+k];
        }
        m[arr[i]]+=1;
    }
    
    return res;
            
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}
