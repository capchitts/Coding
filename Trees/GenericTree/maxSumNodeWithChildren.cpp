/*
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. 
In the sum, data of the node and data of its immediate child nodes has to be taken.
*/

#include<bits/stdc++.h>
using namespace std;

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    if(!root)
        return NULL;
    
    TreeNode<int>* res = NULL;
    queue<TreeNode<int>*> q;
    q.push(root);
    int max_so_far = INT_MIN;
    
    while(!q.empty())
    {
        
        TreeNode<int>* curr = q.front();
        q.pop();
        int curr_node = curr->data;
        for(int i=0;i<curr->children.size();i++)
        {
            curr_node += curr->children.at(i)->data;
            q.push(curr->children.at(i));
        }
        if(curr_node > max_so_far)
        {
            max_so_far = curr_node;
            res = curr;
        }
    }
    
    return res;
    
}
