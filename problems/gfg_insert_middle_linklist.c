
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

//Function to insert a node in the middle of the linked list.
Node* insertInMiddle(Node* head, int x)
{
// Code here
Node* new_node=new Node(x);
Node* temp1=head;
Node* temp2=head;
int count=0;
while(temp1!=NULL){
    count++;
    temp1=temp1->next;
}
if(count%2!=0){
for(int i=0;i<count/2;i++){
    temp2=temp2->next;
}
}
else{
    for(int i=0;i<count/2-1;i++){
        temp2=temp2->next;
    }
}
new_node->next=temp2->next;
temp2->next=new_node;
return head;
}