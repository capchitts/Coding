/*
*O(N^3)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
    int N,M;
    cin>>N>>M;
    int cycles = 0;
    
    //No edges
    if(M < 3)
    {
        cout<<cycles;
    	return 0;
    }
    
    int **edges = new int*[N];
    
    for(int i = 0;i<N;i++)
    {
        edges[i] = new int[N];
    }
    
    
    
    for(int i = 0;i<M;i++)
    {
        int u,v;
        cin>>u>>v;
        
        edges[u][v] = 1;
        edges[v][u] = 1;
    }
    
    for(int i = 0;i<N-2;i++)
    {
        for(int j = i+1;j<N-1;j++)
        {
            //if this is not in edges of curr node no use of further loop
            if(edges[i][j])
            {
                for(int k = j+1;k<N;k++)
                {
                    //check k present in both curr_node adjacency and j;s adjjacency
                    if(edges[j][k] && edges[k][i])
                        cycles += 1;
                }
            }
        }
    }
    
    cout<<cycles;
    
	return 0;
}

