#include <bits/stdc++.h> 
using namespace std; 

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
            vector<int> res;
            set<int> s;
            unordered_map<int,bool> m1;unordered_map<int,bool> m2;unordered_map<int,bool> m3;
            for(int i = 0;i<n1;i++)
            {
                m1[A[i]] = true;
            }
            
            for(int i = 0;i<n2;i++)
            {
                m2[B[i]] = true;
            }
            
            for(int i = 0;i<n3;i++)
            {
                m3[C[i]] = true;
            }
            
            for(int i=0;i<n1;i++)
            {
                int c = A[i];
                if(m2[c] && m3[c])
                {
                    s.insert(c);
                }
            }
            for(auto i = s.begin();i!=s.end();i++)
            {
                res.push_back(*i);
            }
            if(res.size()==0)
                res.push_back(-1);
            
            return res;
}
//without map
void findCommon(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3) 
{ 
    // Initialize starting indexes for ar1[], ar2[] and ar3[] 
    int i = 0, j = 0, k = 0; 
  
    // Iterate through three arrays while all arrays have elements 
    while (i < n1 && j < n2 && k < n3) 
    { 
         // If x = y and y = z, print any of them and move ahead  
         // in all arrays 
         if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) 
         {   cout << ar1[i] << " ";   i++; j++; k++; } 
  
         // x < y 
         else if (ar1[i] < ar2[j]) 
             i++; 
  
         // y < z 
         else if (ar2[j] < ar3[k]) 
             j++; 
  
         // We reach here when x > y and z < y, i.e., z is smallest 
         else
             k++; 
    } 
} 
