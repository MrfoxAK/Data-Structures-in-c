Structure of the node of the linked list is as
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
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        int count=0;
        struct Node* temp1 = head1;
        struct Node* temp2 = head2;
        while(temp2!=NULL){
            temp1 = head1;
            while(temp1!=NULL){
                if(temp1->data+temp2->data == x){
                    count++;
                }
                temp1 = temp1->next;
            }
            temp2 = temp2->next;
        }
        return count;
    }
};