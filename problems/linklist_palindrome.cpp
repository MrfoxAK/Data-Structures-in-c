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

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        int count=0;
        Node* p=head;
        Node* ptr=head;
        while(p!=NULL){
            count=count*10+(p->data);
            p=p->next;
        }
        // count=count/2+1;
        // int i=0;
        // int ln=0,rn=0;
        // while(i<count-1){
        //     ln=ln*10+(ptr->data);
        //     ptr=ptr->next;
        //     i++;
        // }
        // while(ptr!=NULL){
        //     rn=rn*10+(ptr->data);
        //     ptr=ptr->next;
        // }
        // int x=rn;
        // int r,rev=0;
        // while(x>0){
        //     r=x%10;
        //     rev=rev*10+r;
        //     x=x/10;
        // }
        // if(ln==rev){
        //     return 1;
        // }
        // else{
        //     return 0;
        // }
        int r,sum=0;
        int p1 = count;
        while(count>0){
            r=count%10;
            sum=sum*10+r;
            count/=10;
        }
        if(sum==p1){
            return 1;
        }
        else{
            return 0;
        }
    }
};
