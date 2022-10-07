
//User function Template for Java

class Solution
{
    public static void flatten(Node root)
    {
        //code here
        ArrayList<Node>list=new ArrayList<>();
        preOrder(root,list);
        Node temp = list.get(0);
        for(int i=1;i<list.size();i++){
            temp.right=list.get(i);
            temp.left=null;
            temp=temp.right;
        }
    }
    
    static void preOrder(Node root, ArrayList<Node>list){
        if(root==null)return ;

        list.add(root);

        preOrder(root.left,list);

        preOrder(root.right,list);

    }
}