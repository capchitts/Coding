#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    //maintain a visited array
	    bool *visited = new bool[V]();
	    vector<int> res;
	    
	    queue<int> q;
	    q.push(0);
	    res.push_back(0);
	    
	    while(!q.empty())
	    {
	        int curr_node = q.front();
	        q.pop();
	        
	        
	        
	        visited[curr_node] = true;
	        
	        for(int i : adj[curr_node] )
	        {
	            if(!visited[i])
	            {
	                q.push(i);
	                visited[i] = true;
	                res.push_back(i);
	            }   
	        }
	    }
	    
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
