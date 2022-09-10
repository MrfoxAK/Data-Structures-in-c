
#include <stdio.h>
#include <stdlib.h>


struct Node
{
	int data;
	struct Node* next;
};


// } Driver Code Ends
//User function Template for C

//function to insert element at specific position in Circular Linked List
struct Node *sortedInsert(struct Node *head, int data)
{
    //code here
    struct Node * ptr=head;
    struct Node * p=head->next;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    if(data<ptr->data){
        struct Node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newNode->next=head;
        head=newNode;
        temp->next=head;
        return head;
    }
    else if(data<p->data){
        newNode->next=ptr->next;
        ptr->next=newNode;
    }
    else{
        while(p->data<data){
            p=p->next;
            ptr=ptr->next;
        }
        newNode->next=p;
        ptr->next=newNode;
    }
    return head;
}

//{ Driver Code Starts.

void printList(struct Node* node)
{
	struct Node* temp = node;
    if(node != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while(temp != node);
    }
	printf("\n");
	
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int first;
		scanf("%d", &first);
		struct Node *head;
		head = (struct Node *) malloc(sizeof(struct Node));
		head->data = first;
		head->next = NULL;
		struct Node *tail = head;

		for (int i = 1; i < n; ++i)
		{
			int data;
			scanf("%d", &data);
			struct Node *temp;
			temp = (struct Node *) malloc(sizeof(struct Node));
			temp->data = data;
			temp->next = NULL;
			tail->next = temp;
			tail = tail->next;
		}
        tail->next = head;
        
		int data;
		scanf("%d", &data);
        head = sortedInsert(head, data);
        printList(head);
	}
	return 0;
}