struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    int add(Node* root){
        if(root==NULL){
            return 0;
        }
        else{
            return root->data + add(root->left) + add(root->right);
        }
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         if(root==NULL){
             return true;
         }
         if(root->left==NULL && root->right==NULL){
             return true;
         }
         int leftsum = add(root->left);
         int rightsum = add(root->right);
         if(leftsum+rightsum==root->data){
             if(isSumTree(root->left) && isSumTree(root->right)){
                 return true;
             }
         }
         return false;
    }
};