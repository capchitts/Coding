/*
*Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.
*/

#include <bits/stdc++.h> 
using namespace std; 
#define N 5 
  
// The function returns maximum value A(c,d) - A(a,b) 
// over all choices of indexes such that both c > a 
// and d > b. 
int findMaxValue(int mat[][N]) 
{ 
    //stores maximum value 
    int maxValue = INT_MIN; 
  
    // maxArr[i][j] stores max of elements in matrix 
    // from (i, j) to (N-1, N-1) 
    int maxArr[N][N]; 
  
    // last element of maxArr will be same's as of 
    // the input matrix 
    maxArr[N-1][N-1] = mat[N-1][N-1]; 
  
    // preprocess last row 
    
    cout<<"Preprocessing last row "<<endl;	  
    int maxv = mat[N-1][N-1];  // Initialize max 
    for (int j = N - 2; j >= 0; j--) 
    { 
        if (mat[N-1][j] > maxv) 
            maxv = mat[N - 1][j]; 
        maxArr[N-1][j] = maxv;
        cout<<N-1<<"th row and "<<j<<" th column "<< maxArr[N-1][j]<<endl;
    } 
    cout<<endl;
  
    // preprocess last column 
    cout<<"Preprocessing last column "<<endl;
    maxv = mat[N - 1][N - 1];  // Initialize max 
    for (int i = N - 2; i >= 0; i--) 
    { 
        if (mat[i][N - 1] > maxv) 
            maxv = mat[i][N - 1]; 
        maxArr[i][N - 1] = maxv; 
        cout<<i<<"th row and "<<N-1<<" th column "<< maxArr[i][N-1]<<endl;
    } 
    cout<<endl;
    
    // preprocess rest of the matrix from bottom 
    cout<<"Preprocess rest of the matrix from bottom "<<endl;
    for (int i = N-2; i >= 0; i--) 
    { 
        for (int j = N-2; j >= 0; j--) 
        { 
            // Update maxValue 
            if (maxArr[i+1][j+1] - mat[i][j] > maxValue) 
                maxValue = maxArr[i + 1][j + 1] - mat[i][j]; 
  
            // set maxArr (i, j) 
            maxArr[i][j] = max(mat[i][j], max(maxArr[i][j + 1], maxArr[i + 1][j]) ); 
            cout<<i<<"th row and "<<j<<" th element is: "<<maxArr[i][j]<<endl;
        } 
        cout<<endl;
    } 
  
    return maxValue; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int mat[N][N] = { 
                      { 1, 2, -1, -4, -20 }, 
                      { -8, -3, 4, 2, 1 }, 
                      { 3, 8, 6, 1, 3 }, 
                      { -4, -1, 1, 7, -6 }, 
                      { 0, -4, 10, -5, 1 } 
                    }; 
    cout << "Maximum Value is " << findMaxValue(mat)<<endl; 
  
    return 0; 
} 

