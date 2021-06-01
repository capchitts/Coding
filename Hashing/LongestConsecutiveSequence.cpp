#include <bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int,bool> m;
    vector<int> res;
    
    for(int i = 0;i<n;i++)
    {
        //create vector with the element in it
        m[arr[i]] = true;
    }
    
    /*traverse again to create final ans for each integer
    for(int i=0;i<n;i++)
    {
        
        while(true)
        {
            int curr = arr[i] +1;
            
            if(m.count(curr) > 0)
            {
                for(int j = 0;j<m[curr].size();j++)
                {
                    m[arr[i]].push_back(m[curr].at(j));
                }
            }
            
            break;
        }
    }*/
    
    //find the largest vector
    int maxx_len = 1;
    int key = arr[0];
    int curr = key+1;
	while(true)
    {	
        if(m.count(curr) >0)
        {
            maxx_len++;
            curr++;
            
        }
        else
            break;
    }
    
    for(int i = 1;i<n;i++)
    {
        curr = arr[i]+1;
        int c_len = 1;
    	
        while(true)
    	{		
        
        	if(m.count(curr) >0)
        	{
            	c_len++;
            	curr++;
            
        	}
        	else
            	break;
    	}
        
        if(c_len > maxx_len)
        {
            key = arr[i];
            maxx_len = c_len;
        }
    	   
    }
    
    if(maxx_len==1)
        res.push_back(key);
	
    else
    {
        res.push_back(key);
        res.push_back(key + maxx_len-1);
    }
    
    return res;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    cout << ans[0];
    if (ans.size() > 1) {
        cout << " " << ans[ans.size() - 1];
    }

    delete[] arr;
}
