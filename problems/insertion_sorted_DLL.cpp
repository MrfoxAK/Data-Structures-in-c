
/*structure of the node of the DLL is as
struct Node {
	int data;
	struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
//Return the head after insertion
Node* sortedInsert(Node * head, int x)
{
	Node *n = new Node,*t = head;
	n->data = x;
	if(head->data>=x){
	    n->next = head;
	    head->prev = n;
	    
	    return n;
	}
	while(t->next && t->data<=x && t->next->data<=x)t = t->next;
	n->next = t->next;
	if(t->next)t->next->prev = n;
	t->next = n;
    n->prev = t;
    return head;
}