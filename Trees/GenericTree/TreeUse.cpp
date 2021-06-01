#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise()
{
	int rootdata;
	cout<<"Enter the root data: ";
	cin>>rootdata;
	TreeNode<int>* root = new TreeNode<int>(rootdata);
	queue<TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	
	while(!pendingNodes.empty())
	{
		TreeNode<int>* curr = pendingNodes.front();
		
		pendingNodes.pop();
		
		int n = 0;
		cout<<"Enter number of children of node "<<curr->data<<"  have: ";
		cin>>n;
		
		for(int i = 0;i<n;i++)
		{
			int data;
			cout<<"Enter "<<i+1<<" child's data: ";
			cin>>data;
			
			//dynamically creating of node is crucial because it is now in heap memory , otherwise it would be lost in case of static allotment
			TreeNode<int>* child = new TreeNode<int>(data);
			cout<<endl;
			
			curr->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	
	return root;
	
}

TreeNode<int>* takeInput()
{
	int rootdata;
	cout<<"enter the node's data: ";
	
	cin>>rootdata;
	TreeNode<int>*root = new TreeNode<int>(rootdata);
	
	int n;
	cout<<"Enter the number of children the node have: ";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	
	return root;
}

void printTree(TreeNode<int>* root) {
	
	//edge case , not a base case because we will never reach this case from a valid input
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]);
	}
}
void printPreOrder(TreeNode<int>* root) {
    // Write your code here
    if(!root)
        return;
    cout<<root->data<<" ";
    
    for(int i = 0;i<root->children.size();i++)
    {
        printPostOrder(root->children.at(i));
    }
    
    
    return;
    
        
}

void deleteTree(TreeNode<int>* root)
{
	if(!root)
		return;
	
	for(int i = 0;i<root->children.size();i++)
	{
		deleteTree(root->children.at(i));
	}
	//delete calls the objects destructor
	delete root;
}


void printPostOrder(TreeNode<int>* root) {
    // Write your code here
    if(!root)
        return;
    
    for(int i = 0;i<root->children.size();i++)
    {
        printPostOrder(root->children.at(i));
    }
    
    cout<<root->data<<" ";
    return;
    
        
}

int main()
{	
	/*TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	
	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
	TreeNode<int>* root = takeInputLevelWise();
	printTree(root);
	
	return 1;
}
