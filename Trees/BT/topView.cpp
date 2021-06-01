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


class Solution{
  public:
    // function should print the topView of the binary tree
    void getMap(struct Node *root,int hd,int vd, map<int,pair<int,int>> &m)
    {
        if(!root)
            return;
        
        if(m.count(hd)==0)
        {
            m[hd] = make_pair(root->data,vd);
        }
        //check if already present node at same horizontal distance is at more depth then update with lesser depth
        else if(vd < m[hd].second)
        {
            m[hd] = make_pair(root->data,vd);
        }
        
        getMap(root->left,hd-1,vd+1,m);
        getMap(root->right,hd+1,vd+1,m);
        
    }
    vector<int> topView(struct Node *root)
    {
        if (root == NULL)
            return vector<int>();
        
        //key is horizontal distance and value is node data
        map<int,pair<int,int>> m;
        //vd is to make sure the value in corresponding hd slot is from least deep node
        getMap(root,0,0,m);
        
        vector<int> res;
        map<int,pair<int,int>> :: iterator itr;
        for(itr = m.begin();itr!=m.end();itr++)
        {
            res.push_back(itr->second.first);
        }
        
        return res;
        
        
    }

};

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        Solution obj;
        vector<int> res = obj.topView(root);
        
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}

