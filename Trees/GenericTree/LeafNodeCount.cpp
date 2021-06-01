int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
    if(!root)
        return 0;
    if(root->children.size()==0)
    {
        return 1;
    }
    
    
    int small_res = 0;
    for(int i = 0;i<root->children.size();i++)
    {
    	    small_res += getLeafNodeCount(root->children.at(i));
    }
    
    return small_res;
}
