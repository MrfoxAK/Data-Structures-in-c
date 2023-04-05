/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    void inorder(Node* root,vector<Node*>&v)

    {

        if(root==NULL)

            return;

            

        inorder(root->left,v);

        v.push_back(root);

        inorder(root->right,v);

        

    }

    

    

    Node * inOrderSuccessor(Node *root, Node *x)

    {

       vector<Node*>v;

       inorder(root,v);

       int n=v.size();

       for(int i=0;i<v.size();i++)

       {

           if(x==v[i] and i<n-1)

           {

               return v[i+1];

           }

       }

       

       Node* res=new Node(-1);

       return res;

    }
};