#include <bits/stdc++.h>
using namespace std;

int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int, int> map;
    int res = 0;

    for(int i =0; i< n;i++)
    {
       if(map.count(-arr[i]) > 0)
       {
           res += map[-arr[i]];
       }
       
        map[arr[i]]++;
    }
    
    return res;
}


int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}	
