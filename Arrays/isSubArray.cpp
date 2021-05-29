#include <bits/stdc++.h>
using namespace std;

bool isSubArray(int *arr1, int m, int *arr2, int n)
{
    unordered_set<int> s1;
    unordered_set<int> s2;
    
    for(int i=0;i<m;i++)
    {
        s1.insert(arr1[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        s2.insert(arr2[i]);
    }
    
    if(s1==s2)
        return true;
    
    unordered_set<int>::iterator itr;
    for(itr = s2.begin();itr!=s2.end();itr++)
    {
        if(s1.find(*itr)==s1.end())
        {
            return false;
        }
    }
    
    return true;
    
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    int arr1[m],arr2[n];
	    for(int i = 0;i<m;i++)
	    {
	        cin>>arr1[i];
	    }
	    
	     for(int i = 0;i<n;i++)
	    {
	        cin>>arr2[i];
	    }
	    
	    if(isSubArray(arr1,m,arr2,n))
	        cout<<"Yes"<<endl;
	    else
	        cout<<"No"<<endl;
	}
	return 0;
}
