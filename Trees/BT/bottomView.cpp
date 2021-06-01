#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that returns the bottom view.
void getMap(Node *root,int hd, int vd, map<int,pair<int,int>>& m)
{
    if(!root)
        return;
    
    
    if(m.count(hd)==0)
    {
        m[hd] = make_pair(root->data,vd);
    }
    //>= , equals to plays an important role in considering the nodes that come later in level order traversal and updating those.
    else if(vd >= m[hd].second)
    {
        m[hd] = make_pair(root->data,vd);
    }
    
    getMap(root->left,hd-1,vd+1,m);
    getMap(root->right,hd+1,vd+1,m);
    
    return;
   
}
vector <int> bottomView(Node *root)
{
   // Your Code Here
   if(!root)
    return vector<int>();
   
    
   map<int, pair<int,int>> m;
   getMap(root, 0, 0, m);
   
   vector<int> res;
   map<int, pair<int,int>> :: iterator itr;
   
   for(itr = m.begin();itr!=m.end();itr++)
   {
       res.push_back(itr->second.first);
   }
   
   return res;
   
    
   
}

