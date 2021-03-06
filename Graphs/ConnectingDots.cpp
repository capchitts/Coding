/*
* 
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.

Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.

Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns of the board. 
Each of the following N lines contain M characters. Please note that characters are not space separated. Each character is an uppercase Latin letter.

Output Format :
Print true if there is a cycle in the board, else print false.
Constraints :
2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second

Sample Input 1:
3 4
AAAA
ABCA
AAAA

Sample Output 1:
true
*
*
*/

#include <bits/stdc++.h>
using namespace std;

void initialize(bool ** visited,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            visited[i][j]=false;
    }
}

//pi and pj are starting points , i, j are for recursion and col stores the color , visited to maintain visited cells and n,m are static
bool dfs(char board[][MAXN],char col,int pi,int pj,int i,int j,int n,int m,bool **visited){
    
    //cout<<i<<" "<<j<<endl;
    
    //checking that these dots are different from starting points and also are valid , finally if all are visited then colors are same and we got a cyce of atleast 4
    bool d1=(i+1<n && !(i+1==pi && j==pj) && visited[i+1][j]);
    bool d2=(j+1<m && !(i==pi && j+1==pj) && visited[i][j+1]);
    bool d3=(i-1>=0 && !(i-1==pi && j==pj)&& visited[i-1][j]);
    bool d4=(j-1>=0 && !(i==pi && j-1==pj) && visited[i][j-1]);
    
    if(d1 || d2 || d3 || d4)
        return true;
    
    bool ans=false;
    
    visited[i][j]=true;
    
    //Neigbor down
    if(i+1<n && board[i+1][j]==col && !visited[i+1][j])
        ans=ans || dfs(board,col,i,j,i+1,j,n,m,visited);
    
    //Neigbor right
    if(j+1<m && board[i][j+1]==col && !visited[i][j+1])
        ans=ans || dfs(board,col,i,j,i,j+1,n,m,visited);
    
    //Neigbor up
    if(i-1>=0 && board[i-1][j]==col && !visited[i-1][j])
        ans=ans || dfs(board,col,i,j,i-1,j,n,m,visited);
    
    //Neigbor left
    if(j-1>=0 && board[i][j-1]==col && !visited[i][j-1])
        ans=ans || dfs(board,col,i,j,i,j-1,n,m,visited);
    
    return ans;
}

int solve(char board[][MAXN],int n, int m)
{
	// Write your code here.
    bool **visited=new bool*[n];
    
    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
    }
    
    initialize(visited,n,m);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            bool ans=false;
            if(!visited[i][j])
            {
                char color=board[i][j];
                ans=dfs(board,color,i,j,i,j,n,m,visited);
                initialize(visited,n,m);
                
                //cout<<"======"<<endl;
                //cout<<endl;
                //cout<<ans<<endl;
                
                if(ans)
                    return 1;
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

    cout << (hasCycle(board, n, m) ? "true" : "false");
}

