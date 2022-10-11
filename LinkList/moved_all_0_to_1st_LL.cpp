
// my logic
void moveZeroes(struct Node **head)
{
    //Your code here
    struct Node *ptr=*head;
    struct Node *p=ptr->next;
    while(p->next!=NULL){
        if(p->data == 0){
            ptr->next=p->next;
            p->next=*head;
            *head=p;
        }
        ptr=ptr->next;
        p=ptr->next;
    }
}




//other's logic

//User function Template for C++
/* Linked List Node structure
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
// Move Zeros to the front of the list
void moveZeroes(struct Node **head)
{
    Node *z=*head,*nz=*head,*x=*head;
    x=x->next;
    while(x){
        if(x->data){
            nz->next=x;
            x=x->next;
            nz=nz->next;
        }else{
           Node *te=x;
           x=x->next;
           te->next=z;
           z=te;
        }
    }
    nz->next=NULL;
    *head=z;   
}