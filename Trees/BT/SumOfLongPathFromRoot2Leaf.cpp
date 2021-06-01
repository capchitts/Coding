#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


int sumOfLongRootToLeafPath(Node* root);

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<sumOfLongRootToLeafPath(root)<<endl;
  }
  return 0;
}// } Driver Code Ends


//User function Template for C++
/*
structure of the node of the binary tree is as
struct Node {
	int data;
	Node* left, *right;
};
*/
// your task is to complete this function
pair<int,int> height(Node *root,int sum,int h)
{
    if(!root)
        return make_pair(0,0);
    if(!root->left && !root->right)
    {
        return make_pair(sum+root->data,h);
    }
    
    pair<int,int> l = height(root->left , sum+root->data,h+1);
    pair<int, int> r = height(root->right, sum+root->data,h+1);
    
    if(l.second > r.second)
    {
        return l;
    }
    else if(l.second == r.second)
    {
        return make_pair(max(l.first,r.first),r.second);
    }
    else
    {
        return r;
    }
}

int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	if(!root)
	 return 0;
	
	pair<int,int> res = height(root,0,0);
	return res.first;
	
}
