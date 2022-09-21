

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

//Function to find the length of a loop in the linked list.
int countNodesinLoop(struct Node *head)
{   
    Node*slow=head;
    int count = 1;
        Node*fast=head;
        Node*temp=NULL;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
            fast=fast->next;
            }
            slow=slow->next;
            if(fast==slow)
            {  
               slow=slow->next;
               while(fast!=slow)
               {
                   slow=slow->next;
                   count++;
               }
               return count;
            }
        }
        return 0;
}