void replaceHelper(BinaryTreeNode<int>* root, int& sum)
{
    if(!root)
        return;
    
    if(!root->left && !root->right)
    {
    	//update sum
        sum += root->data;
        //update node
        root->data = sum;
        return;
    }
    //go first to right as there are larger or equal elements present
    replaceHelper(root->right,sum);
    
    //add sum after it gets updated from right subtree
    root->data += sum;
    //update sum
    sum = root->data;
    
    //go to left subtree
    replaceHelper(root->left,sum);
    
    return;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
    int sum = 0;
    replaceHelper(root,sum);
    return;
}
