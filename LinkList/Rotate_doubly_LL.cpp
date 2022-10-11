
/*
typedef struct node
{
  int data;
  struct node*next,*prev;
  
  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
} Node;
*/

class Solution {
public:
    Node *rotateDLL(Node *start,int p)
    {
        //Add your code here
        Node* ptr=start;
        Node* p1=start;
        Node* last=start;
        Node* s;
        while(p){
            p1=p1->next;
            p--;
        }
        // return p1;
        s=p1->prev;
        while(last->next!=NULL){
            last=last->next;
        }
        start=p1;
        p1->prev=NULL;
        last->next=ptr;
        ptr->prev=last;
        s->next=NULL;
        return start;
    }
};