/*
Time complexity: O(N)
Space complexity: O(H)
where N is the number of nodes in the input BST
and H is the height of the input BST
*/

class Base 
{
     public:
	Node<int>* head;
        Node<int>* tail;
        Base() 
        {
            head = NULL;
            tail = NULL;
        }
};


Base constructLinkedListHelper(BinaryTreeNode<int>* root)
{
	Base combinedList;
	if (root == NULL) {
		return combinedList;
	}
	
	Base leftList = constructLinkedListHelper(root->left);
	Base rightList = constructLinkedListHelper(root->right);

	Node<int>* newNode = new Node<int>(root->data);	
	
	if(leftList.tail != NULL) 
	{
		leftList.tail->next = newNode;
	}

	newNode->next = rightList.head;
	if(leftList.head != NULL) 
	{
		combinedList.head = leftList.head;
	} 
	else
	{
		combinedList.head = newNode;
	}
	
	if(rightList.tail != NULL) 
	{
		combinedList.tail = rightList.tail;
	} 
	else 
	{
		combinedList.tail = newNode;
	}
	
	return combinedList;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) 
{
	Base list = constructLinkedListHelper(root);
	return list.head;
}
