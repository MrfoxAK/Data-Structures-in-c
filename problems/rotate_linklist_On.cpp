/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// in O(n)

class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        
        Node *left=head,*right=NULL;
        int i=0;
        while(i<k-1)
        {
            left=left->next;
            i++;
        }
        if(left->next==NULL)
        {
            return head;
        }
        right=left->next;
        left->next=NULL;
        Node *trav=right;
        while(trav->next!=NULL)
        {
            trav=trav->next;
        }
        trav->next=head;
        head=right;
        return head;
    }
};

