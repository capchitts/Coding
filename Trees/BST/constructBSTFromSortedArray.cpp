BinaryTreeNode<int>* helper(int *input, int si, int ei)
{
    if(si > ei)
        return NULL;
    
    //calculate mid index
    int mid = (si+ei)/2;
    
    //allocate memory for the node
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    
    //call on left and right
    root->left = helper(input,si,mid-1);
    root->right = helper(input,mid+1, ei);
    
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    
    return helper(input,0,n-1);
    
}
