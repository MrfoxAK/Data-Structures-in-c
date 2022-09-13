/*structure of a node of the linked list is as
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
// Function should return 0 is length is even else return 1


int isLengthEvenOrOdd(struct Node* head)
{
   Node* temp=head;
   int len=0;
   while(temp!=NULL){
       len++;
       temp=temp->next;
   }
   return (len%2==0)?0:1;
}