/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/
#include <bits/stdc++.h>


// Data structure to store information about binary tree rooted under a node
class SubTreeInfo
{
    public:
		// stores the min and the max value in the binary tree rooted under the
		// current node. They are relevant only if isBST flag is true
		int min, max;

		// stores the size of largest BST in binary tree rooted under
		// the current node
		int height;

		// true if binary tree under the current node is a BST
		bool isBST;

		// Constructor
		SubTreeInfo(int min, int max, int height, bool isBST)
		{
			this->min = min;
			this->max = max;
			this->height = height;
			this->isBST = isBST;
		}
        
};

// Recursive function to find the size of the largest BST in a given binary tree
SubTreeInfo* findLargestBST(BinaryTreeNode<int> * root)
{
	// Base case: empty tree
	if (root == nullptr)
		return new SubTreeInfo(INT_MAX, INT_MIN, 0, true);

	// Recur for left subtree and right subtrees
	SubTreeInfo* left  = findLargestBST(root->left);
	SubTreeInfo* right = findLargestBST(root->right);

	SubTreeInfo* info = NULL;

	// Check if binary tree rooted under the current root is a BST

	// 1. Left and right subtree are also BST
	// 2. The value of the root node should be more than the largest value
	//	in the left subtree
	// 3. The value of the root node should be less than the smallest value
	//	in the right subtree
	if (left->isBST && right->isBST && (root->data > left->max && root->data < right->min))
	{
		info = new SubTreeInfo(min(root->data, min(left->min, right->min)),
						max(root->data, max(left->max, right->max)),
						max(left->height,right->height)+1,
						true);
	}
	else
	{
		// If binary tree under the current root is not a BST
		// return the size of largest BST in its left and right subtree

		info = new SubTreeInfo(0, 0,
						max(left->height, right->height)+1,
						false);
	}

	// deallocate the memory for left and right subtrees info node
	delete(left), delete(right);

	return info;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
	SubTreeInfo* res = findLargestBST(root);
    
    if(res == NULL)
        return 0;
    
    return res->height;
}

