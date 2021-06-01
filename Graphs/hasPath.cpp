#include <bits/stdc++.h>
using namespace std;

bool hasPath(bool **graph, int v1, int v2,int v)
{
    queue<int> q;
    bool *visited = new bool[v]();
    q.push(v1);
    visited[v1] = true;
    
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        
        for(int i = 0;i<v;i++)
        {
            if(graph[s][i] && visited[i]==false)
            {
                visited[i] = true;
                q.push(i);
                if(i == v2)
                    break;
            }
        }
    }
    bool ans = visited[v2];
    delete [] visited;
    
    return ans;
    
}
int main() {
    // Write your code here
    int v, e;
    cin >> v >> e;
    
    bool** graph = new bool*[v];
    
    for (int i = 0; i < v; ++i) 
    {
    	graph[i] = new bool[v]();
    }
    
    for (int i = 0, a, b; i < e; ++i) 
    {
    	cin >> a >> b;
    	graph[a][b] = true;
    	graph[b][a] = true;
    }
    
    int v1,v2;
    cin>>v1>>v2;
    
    bool ans = hasPath(graph, v1, v2,v);
    
    if(ans)
        cout<<"true";
    else
        cout<<"false";
    
    for (int i = 0; i < v; ++i) 
    {
    	delete[] graph[i];
    }
    delete[] graph;
    
    
}
