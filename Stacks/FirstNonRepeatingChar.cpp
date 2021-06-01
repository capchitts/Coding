#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string res = "";
		    queue<char> q;
		    int *arr = new int[26];
		    
		    
		    for(int i=0;i<26;i++)
		    {
		        arr[i] = 0;
		    }
		    
		    for(int i = 0;i < A.length();i++)
		    {
		        //push into queue
		        q.push(A[i]);
		        //increment count in arr
		        arr[A[i] - 'a'] += 1;
		        
		        while(!q.empty())
		        {
		            if(arr[q.front() - 'a'] > 1)
		                q.pop();
		            else
		            {
		                res += q.front();
		                break;
		            }
		        }
		        
		        if(q.empty())
		            res += '#';
		    }
		    
		    return res;
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
} 
