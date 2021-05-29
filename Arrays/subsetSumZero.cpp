
#include <bits/stdc++.h>
using namespace std;


bool subArrayExists(int arr[], int n);
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    	if (subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}// } Driver Code Ends


//Complete this function
bool subArrayExists(int arr[], int n)
{
    //store the sum till ith element in set and if sum is already present in set then zero sum exists
    set<int> s;
    
    for(int i=0;i<n;i++)
    {
        sum +=res[i];
        if(sum==0||s.find(sum)!=s.end())
            return true;
        
        s.insert(sum);
    }
    
    return false;
}


