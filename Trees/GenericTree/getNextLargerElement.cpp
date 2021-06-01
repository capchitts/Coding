TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
    if(!root)
        return NULL;
    
    TreeNode<int>* res = NULL;
    queue<TreeNode<int>*> q;
    
    q.push(root);
    
    if(root->data > x)
    {
        res = root;
    }
    
    while(!q.empty())
    {
        TreeNode<int>* curr = q.front();
        q.pop();
        
        for(int i = 0;i<curr->children.size();i++)
        {
            int curr_data = curr->children.at(i)->data;
            if(curr_data > x )
            {
                if(!res || res->data > curr_data)
                {
                    res = curr->children.at(i);
                }
            }
            q.push(curr->children.at(i));
        }
    }
    return res;
}
