#include <bits/stdc++.h>
using namespace std;

bool helper(BinaryTreeNode<int> *root, int min, int max)
{
	if(!root)
         return true;
    
    if(root->data < min || root->data > max)
        return false;
    
    return helper(root->left, min, root->data) && helper(root->right, root->data, max);
}

bool isBST(BinaryTreeNode<int> *root){
       /* Don't write main().
	* Don't read input, it is passed as function argument.
	* Return output and don't print it.
	* Taking input and printing output is handled automatically.
	*/
    
    return helper(root, INT_MIN, INT_MAX);
}
