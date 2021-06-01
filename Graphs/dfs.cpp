#include<iostream>
using namespace std;


void dfs(int** edges, int n, int sv, bool* visited){
  //print the vertex
  cout << sv << endl;
  
  //mark it visited
  visited[sv] = true;
  
  //loop over all other vertices 
  for(int i=0; i<n; i++){
    
    if(i==sv){
      continue;
    }
    //if an edge exist and not visited yet go further level down. 
    if(edges[sv][i]==1){
      if(visited[i]){
        continue;
      }
      //called only for unvisited vertex
      dfs(edges, n, i, visited);
    }
  }
}

int main(){
  int n;
  int e;
  cout<<"Enter the number of vertices and edges"<<endl;
  cin >> n >> e;
  
  //2d dynamic array for adjacency matrix
  int** edges = new int*[n];
  
  for(int i=0; i<n; i++){
    //dynamic allocation of memory
    edges[i]=new int[n];
    
    for(int j=0; j<n; j++){
      edges[i][j]=0;
    }
  }
  
  cout<<"Enter the edge (u, v)"<<endl;
  for(int i=0; i<e; i++){
    int f,s;
    cin >> f >> s;
    edges[f][s]=1;
    edges[s][f]=1;
  }

  bool* visited = new bool[n];

  for(int i=0; i<n; i++){
    visited[i]=false;
  }

  dfs(edges, n, 0, visited);
  
   //for disconnected graphs
  for(int i = 0;i<n;i++)
  {
      if(!visited[i])
          dfs(edges,n,i,visited);
  }
  
  // Delete all the memory
  delete[] visited;
  for(int i = 0;i<n;i++)
  {
  	delete[] edges[i];
  }
  
  delete[] edges;
  
  return 0;
}
