/*
To print the information of a node with data D, you need to follow the exact format :

           D:L:X,R:Y

Where D is the data of a node present in the binary tree. 
X and Y are the values of the left(L) and right(R) child of the node.
Print -1 if the child doesn't exist.
*/

void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    if(!root)
        return;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty())
    {
        BinaryTreeNode<int>* curr = q.front();
        q.pop();
        cout<<curr->data<<":";
        if(curr->left)
        {
         	cout<<"L:"<<curr->left->data;
        	q.push(curr->left);
        }
        if(!curr->left)
           cout<<"L:-1"; 
        
        if(curr->right)
        {
            cout<<",R:"<<curr->right->data<<endl;
        	q.push(curr->right);
        }
        if(!curr->right)
           cout<<",R:-1"<<endl; 
        
    }
    
    return;
}
