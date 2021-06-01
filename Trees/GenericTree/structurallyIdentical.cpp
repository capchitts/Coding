bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    // Write your code here
    if(!root1 && !root2)
        return true;
    //check the data of root
    bool ans = false;
    
    if(root1->data == root2->data && root1->children.size() == root1->children.size())
    {
    	ans = true;
        for(int i = 0;i<root1->children.size();i++)
        {
            ans = ans && areIdentical(root1->children.at(i),root2->children.at(i));
            
        }
        
    }
    else
    {
        ans = false;
    }
    
    return ans;
    
}
