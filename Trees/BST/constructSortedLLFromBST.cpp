void helper(BinaryTreeNode<int>* root, vector<int>& res)
{
	if(!root)
        return;
    
    helper(root->left,res);
    res.push_back(root->data);
    helper(root->right,res);
    
    return;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    vector<int> res;
    helper(root,res);
    
    if(res.size()==0)
        return NULL;
    
    Node<int>*head = new Node<int>(res.at(0));
    Node<int>*curr = head;
    
    for(int i = 1;i<res.size();i++)
    {
        Node<int>*tmp = new Node<int>(res.at(i));
        curr->next = tmp;
        curr = curr->next;
        
    }
    
    return head;
}
