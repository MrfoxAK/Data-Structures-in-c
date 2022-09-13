/*
structure of the node of the list is as
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

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node* temp=new Node(data);
        if(head==NULL){
           return temp;
       }
       //jb first node hi km ho data se
       if(temp->data<head->data){
           temp->next=head;
           return temp;
       }
       //rest cases
       Node* curr=head;
       while(curr->next!=NULL && curr->next->data<data){
           curr=curr->next;
       }
       temp->next=curr->next;
       curr->next=temp;
       return head;
    }
};