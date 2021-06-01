/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include <bits/stdc++.h>
using namespace std;

void inorder_traversal(BinaryTreeNode<int> *root,unordered_map<int,bool>& m)
{
    if(!root)
        return;
    
    inorder_traversal(root->left,m);
    m[root->data] = true;
    inorder_traversal(root->right,m);
    
    return;
    
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    if(!root || sum == 0)
        return;
    //do the traversal and store it in a map
    unordered_map<int,bool> m;
    
    inorder_traversal(root,m);
    
    unordered_map<int,bool>::iterator itr;
    
    for(itr = m.begin();itr!=m.end();itr++)
    {
        if((itr->first) != (sum - itr->first))
        {
            try 
            {
      				m.at(sum - itr->first);
   			} 
            catch(const out_of_range &e) 
            {
     			m.at(itr->first) = false;
                continue;
   			}
            if(itr->second == true && m[sum - itr->first]==true)
            {
            	itr->second = false;
            	m[sum - itr->first] = false;
            
            	//printing
            	if(itr->first < sum - itr->first)
            		cout<<itr->first<<" "<<sum - itr->first<<endl;
            	else
                	cout<<sum - itr->first<<" "<<itr->first<<endl;
            }
        }
    }
    
    return;
}
