The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     Node* curr=head;

     if(head==NULL)

      return NULL;

      

      unordered_set<int>s;

      

      while(curr && curr->next){

           s.insert(curr->data);

         if(s.find(curr->next->data) != s.end())

           {

               Node* temp=curr->next;

               curr->next=curr->next->next;

               temp->next=NULL;

           }

           else 

                   curr=curr->next;

           

      } 

      return head;
    }
};