int height(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
      int h = 0;
      if(!root)
          return 0;
      
      if(root->children.size()==0)
          return 1;
    
      for(int i = 0;i<root->children.size();i++)
      {
          h = max(h,height(root->children[i]));
      }
    
      return h+1;

}

