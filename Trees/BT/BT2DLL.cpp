class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node* helper(Node *root)
    {
        if(!root)
            return NULL;
        
        if(!root->left && !root->right)
        {
            return root;
        }
        
        
        Node *left_head = helper(root->left);
        // traverse the right side till NULL
        Node* curr = left_head;
        
        if(curr)
        {
            while(curr->right)
            {
                curr = curr->right;    
            }
            curr->right = root;
            root->left = curr;
        }
        
        Node * right_head = helper(root->right);
        //traverse the left side till NULL
        curr = right_head;
        if(curr)
        {
            while(curr->left)
            {
                curr = curr->left;
            }
            curr->left = root;
            root->right = curr;
        }
        
        return root;
            
    }
    
    Node * bToDLL(Node *root)
    {
        // your code here
        if(!root)
            return NULL;
            
        helper(root);
        
        //find the head of DLL
        Node *res = root;
        while(res->left)
        {
            res = res->left;
        }
        
        
        root = res;
        return root;
    }
};
	
