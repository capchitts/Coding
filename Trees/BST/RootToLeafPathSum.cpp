void rootToLeafHelper(BinaryTreeNode<int> *root, int k, string path)
{
    if(!root)
        return;
    if(!root->left && !root->right)
    {
        if(k==root->data)
            cout<<path+to_string(root->data)<<endl;
        
        return;
    }
    path = path + to_string(root->data) + " ";
    
    rootToLeafHelper(root->left, k - root->data, path);
    rootToLeafHelper(root->right,k - root->data, path);
    
    return;
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    
    rootToLeafHelper(root, k , "");
    
}
