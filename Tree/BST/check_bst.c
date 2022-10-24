{
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    bool solve(Node* root, int min, int max){

        // base case

        if(root==NULL) return true;

        

        bool l = solve(root->left, min, root->data);

        bool r = solve(root->right, root->data, max);

        bool ans = root->data > min && root->data < max;

        return l&&r&&ans;

    }

    

    public:

    bool isBST(Node* root) 

    {

        int min = INT_MIN;

        int max = INT_MAX;

        

        return solve(root,min,max);

    }
};



// bool isBST(Node* node, int minKey, int maxKey)
// {
//     // base case
//     if (node == nullptr) {
//         return true;
//     }
 
//     // if the node's value falls outside the valid range
//     if (node->data < minKey || node->data > maxKey) {
//         return false;
//     }
 
//     // recursively check left and right subtrees with an updated range
//     return isBST(node->left, minKey, node->data) &&
//             isBST(node->right, node->data, maxKey);
// }
 
// // Function to determine whether a given binary tree is a BST
// void isBST(Node* root)
// {
//     if (isBST(root, INT_MIN, INT_MAX)) {
//         printf("The tree is a BST.");
//     }
//     else {
//         printf("The tree is not a BST!");
//     }
// }
 