

//User function Template for Java



class BST
{   
    //Function to find the lowest common ancestor in a BST. 
	Node LCA(Node root, int n1, int n2)
	{
        // code here. 
        if(root==null) return null;
        if(root.data==n1 || root.data == n2) return root;
        Node left = LCA(root.left,n1,n2);
        Node right = LCA(root.right,n1,n2);
        if(left == null) return right;
        if(right == null) return left;
        return root;
    }
    
}