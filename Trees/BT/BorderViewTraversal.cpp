/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 
Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 
*/
void printLeaves(Node* root,vector<int> &res)
{
    if (root == NULL)
        return;

    printLeaves(root->left,res);

    // Print it if it is a leaf node
    if (!(root->left) && !(root->right))
        res.push_back(root->data);

    printLeaves(root->right,res);
}

// A function to print all left boundary nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
void printBoundaryLeft(Node* root,vector<int> &res)
{
    if (root == NULL)
        return;

    if (root->left) {

        // to ensure top down order, print the node
        // before calling itself for left subtree
        res.push_back(root->data);
        printBoundaryLeft(root->left,res);
    }
    else if (root->right) {
        res.push_back(root->data);
        printBoundaryLeft(root->right,res);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}

// A function to print all right boundary nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printBoundaryRight(Node* root,vector<int> &res)
{
    if (root == NULL)
        return;

    if (root->right) {
        // to ensure bottom up order, first call for right
        // subtree, then print this node
        printBoundaryRight(root->right,res);
        res.push_back(root->data);
    }
    else if (root->left) {
        printBoundaryRight(root->left,res);
        res.push_back(root->data);
    }
    // do nothing if it is a leaf node, this way we avoid
    // duplicates in output
}


vector <int> printBoundary(Node *root)
{
     //Your code here
     if(!root)
        return vector<int>();
        
     vector<int> res;
     res.push_back(root->data);
     
     printBoundaryLeft(root->left,res);
     
     printLeaves(root->left,res);
     printLeaves(root->right,res);
     
     //to avoid taking root twice
     printBoundaryRight(root->right,res);
     
     return res;
    
}
