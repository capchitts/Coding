#include <bits/stdc++.h>
using namespace std;

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    if(!root)
        return pair<int,int>(-1,-1);
    
    
    pair<int, int> ans(INT_MAX,INT_MIN);
    queue<BinaryTreeNode<int> *>q;
    
    q.push(root);
    
    while(!q.empty())
    {
        BinaryTreeNode<int>* curr = q.front();
        q.pop();
        
        if(ans.first > curr->data)
        {
            ans.first = curr->data;
        }
        
        if(ans.second < curr->data)
        {
            ans.second = curr->data;
        }
        if(curr->left)
        	q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
        
    }
    
    return ans;
}
