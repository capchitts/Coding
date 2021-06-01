#include<bits/stdc++.h>
using namespace std;

int kthLargest(int* arr, int n, int k) {
    // Write your code here
    
    sort(arr,arr+n);
    return arr[n-k];
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;
}
