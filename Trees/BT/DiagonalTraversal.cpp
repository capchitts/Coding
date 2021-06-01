#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


void diagonalPrint(BinaryTreeNode<int>*root,map<int,vector<int>> &res,int level)
{
	if(!root)
		return;
	
	//enter the root in map
	res[level].push_back(root->data);
	
	//recursion on left subtree
	diagonalPrint(root->left,res,level+1);
	
	//recursion on right subtree, level remain same in right subtree
	diagonalPrint(root->right, res, level);
	
	return;
}
void diagonalPrint(BinaryTreeNode<int>* root)
{
	if(!root)
		return;
	
	map<int, vector<int>> res;
	diagonalPrint(root,res,0);
	
	map<int,vector<int>>:: iterator itr;
	for(itr = res.begin();itr!=res.end();itr++)
	{
		vector<int> v = itr->second;
		for(int i = 0;i<v.size();i++)
		{
			cout<<v.at(i)<<" ";
		}
		cout<<endl;
	}
	
}

int main() {

    BinaryTreeNode<int> *root = takeInput();
    diagonalPrint(root);
    
    return 1;
    
}

