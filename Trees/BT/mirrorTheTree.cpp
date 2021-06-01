void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
    if(!root)
        return;
    
    if(!root->left && !root->right)
        return;
    
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    
    //swap the nodes
    BinaryTreeNode<int>* l = root->left;
    root->left = root->right;
    root->right = l;
    
    return;
}
