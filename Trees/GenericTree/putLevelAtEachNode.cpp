void helper(TreeNode<int>* root, int l)
{
    if(!root)
        return;
    
    root->data = l;
    
    for(int i = 0;i<root->children.size();i++)
    {
        helper(root->children.at(i),l+1);
    }
    
    return;
    
}
void replaceWithDepthValue(TreeNode<int>* root) {
    // Write your code here
    if(!root)
        return;
    int level = 0;
    helper(root, level);
}
