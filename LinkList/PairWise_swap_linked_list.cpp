class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        Node* p=head;
        Node* ptr=head->next;
        p->next=ptr->next;
        ptr->next=p;
        head=ptr;
        p=p->next;
        ptr=p->next;
        Node* temp=head->next;
        while(ptr){
            p->next=ptr->next;
            ptr->next=p;
            temp->next=ptr;
            temp=p;
            p=temp->next;
            ptr=p->next;
        }
        return head;
    }
};