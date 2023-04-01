class Solution{
    public:
         int height(struct Node* node){

        // code here 

        if(!node)

        {

            return 0;

        }

        else

        {

            return max(height(node->left),height(node->right))+1;

        }

    }

    bool isBalanced(Node *root)

    {

        //  Your Code here

        if(!root)

        {

            return true;

        }

        int l = height(root->left);

        int r= height(root->right);

        if((abs(l-r)==0 || abs(l-r)==1) && isBalanced(root->left) && isBalanced(root->right))

          return 1;

        return 0;

    }

 

};