/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
*/

#include <bits/stdc++.h>
using namespace std;

void initialize(bool **visited,int N,int M)
{
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
            visited[i][j]=false;
    }
}

//N,M are statis , char [] c is for maintaining which car to look next, i and j tells the position we are in matrix
bool dfs(vector<vector<char>> Graph,char c[],int i,int j,int N,int M,bool ** visited){
    
    //base case as A make the string Coding Ninja ends
    if(Graph[i][j]=='A')
        return true;
    
    visited[i][j]=true;
    
    bool ans=false;
    
    //Neighbor NorthWest
    if(i-1>=0 && j-1>=0 && Graph[i-1][j-1]==c[0] && !visited[i-1][j-1])
        ans=ans || dfs(Graph,c+1,i-1,j-1,N,M,visited);
    
    //Neighbor North
    if(i-1>=0 && Graph[i-1][j]==c[0] && !visited[i-1][j])
        ans=ans || dfs(Graph,c+1,i-1,j,N,M,visited);
    
    //Neighbor NorthEast
    if(i-1>=0 && j+1<M && Graph[i-1][j+1]==c[0] && !visited[i-1][j+1])
        ans=ans || dfs(Graph,c+1,i-1,j+1,N,M,visited);
    
    //Neighbor East
    if(j+1<M && Graph[i][j+1]==c[0] && !visited[i][j+1])
        ans=ans || dfs(Graph,c+1,i,j+1,N,M,visited);
    
    //Neighbor SouthEast
    if(i+1<N && j+1<M && Graph[i+1][j+1]==c[0] && !visited[i+1][j+1])
        ans=ans || dfs(Graph,c+1,i+1,j+1,N,M,visited);
    
    //Neighbor NorthWest South
    if(i+1<N && Graph[i+1][j]==c[0] && !visited[i+1][j])
        ans=ans || dfs(Graph,c+1,i+1,j,N,M,visited);
    
    //Neighbor South West
    if(i+1<N && j-1>=0 && Graph[i+1][j-1]==c[0] && !visited[i+1][j-1])
        ans=ans || dfs(Graph,c+1,i+1,j-1,N,M,visited);
    
    //Neighbor West
    if(j-1>=0 && Graph[i][j-1]==c[0] && !visited[i][j-1])
        ans=ans || dfs(Graph,c+1,i,j-1,N,M,visited);
     visited[i][j]=false;
    return ans;
   
}

int solve(vector<vector<char>> Graph,int N, int M)
{
	// Write your code here.
    
    
}

bool hasPath(vector<vector<char>> &Graph, int n, int m) {
    // Write your code here.
    
    //need to store the entire expected string to recurse over it
    char c[]="CODINGNINJA";
    
    bool **visited=new bool*[N];
    
    for(int i=0;i<N;i++){
        visited[i]=new bool[M];
    }
    
    initialize(visited,N,M);
    
    //searching for every possible c till answer is found
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++){
            bool ans=false;
            if(Graph[i][j]=='C')
            {
                //We need to call 8 times dfs for each neighbor
                ans=dfs(Graph,c+1,i,j,N,M,visited);
                if(ans)
                    return 1;
                else
                    //for further search 
                    initialize(visited,N,M);
            }
        }
    }
    
    return 0;
    
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}

