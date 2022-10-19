
/*Structure of the node of the binary tree is as
struct Node
{
	int data;
	Node *left, *right;
};*/
// function should return the sum of all the 
// leaf nodes of the binary tree 
int sumLeaf(Node* root)
{
    if(!root) return 0;
    if(!root->left && !root->right) return root->data;
    return sumLeaf(root->left) + sumLeaf(root->right);
}