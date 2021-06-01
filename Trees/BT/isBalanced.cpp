#include<bits/stdc++.h>
using namespace std;

int height(BinaryTreeNode<int> *root)
{
    if(!root)
        return 0;
    if(!root->left && !root->right)
    {
        return 1;
    }
    
    return 1 + height(root->left)+ height(root->right);
}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    if(!root || !root->left && !root->right)
        return true;
    
    
    bool ans = isBalanced(root->left) && isBalanced(root->right);
    
    int l_height = height(root->left);
    int r_height = height(root->right);
    
    if(abs(l_height - r_height) > 1)
        return false;
    
    return ans;
    
    
}
