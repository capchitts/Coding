#include <bits/stdc++.h>
using namespace std;

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(!root)
        return NULL;
    
    int maxx = INT_MIN;
    int smaxx = INT_MIN;
    queue<TreeNode<int>*> q;
    vector<TreeNode<int> *> v;
    
    q.push(root);
    maxx = max(root->data,maxx);
    v.push_back(root);
    v.push_back(NULL);
    while(!q.empty())
    {
        TreeNode<int>* curr = q.front();
        q.pop();
            
        for(int i = 0;i<curr->children.size();i++)
        {
            int curr_data  = curr->children.at(i)->data;
            
            if(curr_data > maxx)
            {
                maxx = curr_data;
                smaxx = maxx;
                
                v.at(1) = v.at(0);
                v.at(0) = curr->children.at(i);
                
            }
            if(curr_data < maxx && curr_data > smaxx)
            {
                smaxx = curr_data;
                v.at(1) = curr->children.at(i);
            }
            q.push(curr->children.at(i));
            
        }
    }
    return v.at(1);
}
