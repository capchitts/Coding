int sumOfNodes(TreeNode<int>* root) {
    // Write your code here
    if(!root)
        return 0;
    
    queue<TreeNode<int> *> q;
    q.push(root);
    
    int sum = 0;
    
    while(!q.empty())
    {
		  TreeNode<int>* curr = q.front();
           q.pop();
        
           //add into sum when popped from queue
           sum+=curr->data;
        
           for(int i=0;i<curr->children.size();i++)
           {
               //push children in queue
               q.push(curr->children.at(i));
           }
    }
    
    return sum;
}
