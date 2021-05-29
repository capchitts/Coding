#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int arr[], int n, int k) 
{
        // code here
        unordered_map<int,int> m;
        int count 0;
        
        for(int i=0;i<n;i++)
        {
            m[arr[i]] += 1;
        }
        
        for(int i = 0;i<n;i++)
        {
            int key = k - arr[i];
            if(m[key]>0)
            {
                count+=m[key];
            }
            //same element is not considered twice
            if(k - arr[i] = arr[i])
             count -=1;
        }
        return count/2;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}

