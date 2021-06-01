#include <bits/stdc++.h>
using namespace std;

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int,int> m;
    
    //store in map
    for(int i = 0;i<n;i++)
        m[arr[i]] +=1;
    
    int maxx_freq = INT_MIN;
    int maxx_num = 0;
    
    for(int i=0;i<n;i++)
    {
        if(maxx_freq < m[arr[i]])
        {
            maxx_freq = m[arr[i]];
            maxx_num = arr[i];
        }
        
    }
    
    return maxx_num;
}


int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}
