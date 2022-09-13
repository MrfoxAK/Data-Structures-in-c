
/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head)
{
   if(head==NULL ||head->next==NULL)
       return NULL;
   Node *temp=head;
   int nodes=0;
   while(temp!=NULL)
   {
       nodes++;
       temp=temp->next;
   }
   nodes = nodes/2;
   temp=head;
   for(int i=0;i<nodes-1;i++)
       temp=temp->next;
   temp->next=temp->next->next;
   return head;
}