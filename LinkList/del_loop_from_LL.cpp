structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node * fast = head;
        Node* slow = head;
        
        while(slow && fast && fast->next and fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                break;
            }
        }
        if(slow==head){
            while(fast->next!=slow){
                fast = fast->next;
            }
            fast->next=NULL;
        }
        else if(slow==fast){
            slow=head;
            while(slow->next!=fast->next){
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL;
        }
    }
};