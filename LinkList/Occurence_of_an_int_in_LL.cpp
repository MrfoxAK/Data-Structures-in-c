/*
  Node is defined as 
struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}*head;
*/
class Solution
{
    public:
    int count(struct node* head, int search_for)
    {
        //add your code here
        int count=0;
        struct node* p = head;
        while(p!=NULL){
            if(p->data==search_for){
                count+=1;
            }
            p=p->next;
        }
        return count;
    }
};