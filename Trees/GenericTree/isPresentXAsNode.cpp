bool isPresent(TreeNode<int>* root, int x) {
    // Write your code here
    if(!root)
        return false;
    
    if(root->data == x)
        return true;
    
    bool res = false;
    
    for(int i = 0;i<root->children.size();i++)
    {
     	res = res || isPresent(root->children.at(i),x);   
    }
    
    return res;
}
