#include <bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2) {
	// Write your code here
    /*
    *  TC - O(2^(mn))
    *  SC - O((m+n))
    */ 
    if(s1.empty() && s2.empty())
        return 0;
    
    if(s1.empty() || s2.empty())
        return max(s1.length(),s2.length());
    
    if(s1[0]==s2[0])
        return editDistance(s1.substr(1),s2.substr(1));
    
    int ins_count = editDistance(s1.substr(1),s2);
    int del_count = editDistance(s1,s2.substr(1));
    int rep_count = editDistance(s1.substr(1),s2.substr(1));
    
    return 1 + min(min(ins_count,del_count),rep_count);
        
}
