#include <bits/stdc++.h>
using namespace std;

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    if(!root)
        return NULL;
    
    
    TreeNode<int>* res;
    queue<TreeNode<int>*> q;
    
    int max_so_far = INT_MIN;
    
    q.push(root);
    
    while(!q.empty())
    {
        TreeNode<int>* curr = q.front();
        q.pop();
        
        if(curr->data > max_so_far)
        {
            max_so_far = curr->data;
            res = curr;
        }
        for(int i = 0;i<curr->children.size();i++)
        {
            q.push(curr->children.at(i));
        }
        
    }
    
    return res;
}
