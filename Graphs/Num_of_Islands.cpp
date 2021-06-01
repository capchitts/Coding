#include <bits/stdc++.h>

using namespace std;


int num_of_islands(int **edges, int V, bool *visited)
{
    
    //intuition is to check if all the vertex are visited then we have been through entire network
    
    //this counter is to ensure that in disjoint graph we go to these nodes
    int counter = 0;
    int res = 0;
    queue<int> q;
    while(counter != V)
    {
        //this to make sure dont do redundant work
        if(visited[counter]==true)
        {
            counter +=1;
            continue;
        }
        //bfs
        q.push(counter);
        visited[counter] = true;
		counter += 1;
        
        //will get out of the loop after completing one entire connected component
        while(!q.empty())
        {
            int curr = q.front();
            for(int i = 0;i<V;i++)
            {
                if(edges[curr][i]==1 && !visited[i])
                {
                    //push into queue
                    q.push(i);
                    visited[i] = true;
                }
            }
            q.pop();
        }
        res+=1;
        
   }
	return res;
}

void dfs_helper(int **edges, int V,int sv, bool *visited)
{
	//make the current vertex as visited
    visited[sv] = true;
    
    //traverse all sv connected vertex 
    for(int i = 0;i<V;i++)
    {
        if(edges[sv][i]!=0 && !visited[i])
            dfs_helper(edges,V,i,visited);
    }
    
}

int dfs(int ** edges, int V,bool *visited)
{
    int res = 0;
    for(int i = 0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs_helper(edges,V,i,visited);
        	res+=1;
        }
    }
    return res;
}

int main() {
    // Write your code here
    int V,E;
    cin>>V>>E;
    
    if(E == 0)
    {
        cout<<V;
    }
    else
    {
        int **edges = new int*[V];
        for(int i = 0;i<V;i++)
        {
            edges[i] = new int[V];
            for(int j = 0;j<V;j++)
            {
                edges[i][j] = 0;
            }

        }

        for(int i = 0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            //add the edge
            edges[u][v] = 1;
            edges[v][u] = 1;
        }

        bool *visited = new bool[V];
        for(int i = 0;i<V;i++)
            visited[i] = false;

        //cout<<num_of_islands(edges, V,visited);
        cout<<dfs(edges,V,visited);
    }
    return 0;
}
