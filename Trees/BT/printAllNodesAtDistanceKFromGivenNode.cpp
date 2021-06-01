void printDown(BinaryTreeNode<int> *root, int k)
{
    if(!root||k<0)
        return;
    
    if(k==0)
    {
    	cout<<root->data<<endl;
        return;
    }
    printDown(root->left,k-1);
    printDown(root->right,k-1);    
}


int helper(BinaryTreeNode<int> *root, int node, int k)
{
    if(!root)
        //means node not found
        return -1;
    
    if(root->data == node)
    {
        //simplest case , now just need to go down k nodes and print the value
        printDown(root,k);
        return 0;
    }
    
    // Recur for left subtree 
    int dl = helper(root->left, node, k); 
  
    // Check if target node was found in left subtree 
    if (dl != -1) 
    { 
         // If root is at distance k -1 from target, print root 
         // Note that dl is Distance of root's left child from target 
         if (dl + 1 == k) 
            cout << root->data << endl; 
  
         // Else go to right subtree and print all k-dl-2 distant nodes 
         // Note that the right child is 2 edges away from left child 
         else
            printDown(root->right, k-dl-2); 
  
         // Add 1 to the distance and return value for parent calls 
         return 1 + dl; 
    } 
  
    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE 
    // Note that we reach here only when node was not found in left subtree 
    int dr = helper(root->right, node, k);
    if (dr != -1)
    { 
         if (dr + 1 == k) 
            cout << root->data << endl; 
         else
            printDown(root->left, k-dr-2); 
         return 1 + dr; 
    } 
  
    // If target was neither present in left nor in right subtree 
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
	int ans = helper(root,node,k);
}

