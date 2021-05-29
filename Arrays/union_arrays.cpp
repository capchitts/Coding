#include <bits/stdc++.h>
using namespace std;

vector<int> intersect_arrays(int arr1[],int n1, int arr2[],int n2)
{
        vector<int> res;
        unordered_map<int,bool> m;
        set<int> s;
        int m_arr = 0;
        
        if(n1 > n2)
        {
            m_arr = 1;
        }
        else
        {
            m_arr = 2;
        }
        
        if(m_arr==1)
        {
            for(int i = 0;i<n1;i++)
            {
                m[arr1[i]] = true;
            }
            for(int i = 0;i<n2;i++)
            {
                s.insert(arr2[i]);
            }
            
        }
        else
        {
            for(int i = 0;i<n2;i++)
            {
                m[arr2[i]] = true;
            }
             for(int i = 0;i<n1;i++)
            {
                s.insert(arr1[i]);
            }
        }
        
        set<int, greater<int> >::iterator itr;
        
        for(itr = s.begin();itr!=s.end();itr++)
        {
            if(m.find(*itr)!=m.end())
            {
                res.push_back(*itr);
            }
        }
        
        return res;
        
}

vector<int> union_arrays(int arr1[],int n1, int arr2[],int n2)
{
        vector<int> res;
        unordered_map<int,bool> m;
        set<int> s;
        int m_arr = 0;
        
        if(n1 > n2)
        {
            m_arr = 1;
        }
        else
        {
            m_arr = 2;
        }
        
        if(m_arr==1)
        {
            for(int i = 0;i<n1;i++)
            {
                m[arr1[i]] = true;
            }
            for(int i = 0;i<n2;i++)
            {
                s.insert(arr2[i]);
            }
            
        }
        else
        {
            for(int i = 0;i<n2;i++)
            {
                m[arr2[i]] = true;
            }
             for(int i = 0;i<n1;i++)
            {
                s.insert(arr1[i]);
            }
        }
        
        set<int>::iterator itr;
        
        for(itr = s.begin();itr!=s.end();itr++)
        {
            m[*itr] = true;
        }
        
        unordered_map<int,bool>::iterator itr1;
        for(itr1 = m.begin();itr1!=m.end();itr1++)
        {
        	res.push_back(itr1->first);
        }
        
        return res;
        
}

int main() {
	//code
	int t;
	cin>>t;
	while(t)
	{
	int n1, n2;
	    cin>>n1>>n2;
	    int *arr1 = new int[n1];
	    int *arr2 = new int[n2];
	    
	    for(int i=0;i<n1;i++)
	    {
	        cin>>arr1[i];
	    }
	    
	    for(int j=0;j<n2;j++)
	    {
	        cin>>arr2[j];
	    }
	    
	    vector<int> res = intersect_arrays(arr1,n1,arr2,n2);
	    vector<int>::iterator itr;
	    
	    cout<<"Intersection result"<<endl;
	    for(itr = res.begin();itr!=res.end();itr++)
	    {
	        cout<<(*itr)<<" ";   
	    }
	    cout<<endl;
	    
	    cout<<"Union result"<<endl;
	    res = union_arrays(arr1,n1,arr2,n2);
	    for(itr = res.begin();itr!=res.end();itr++)
	    {
	        cout<<(*itr)<<" ";   
	    }
	    cout<<endl;
	    t--;
	}
	return 0;
}
