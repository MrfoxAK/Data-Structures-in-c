#include <stdio.h>
#include <stdlib.h>
// Linked List Node
struct node {
	int info;
	struct node* link;
};

struct node* start = NULL;

void createList()
{
	if (start == NULL) {
		int n;
		printf("\nEnter the number of nodes: ");
		scanf("%d", &n);
		if (n != 0) {
			int data;
			struct node* newnode;
			struct node* temp;
			newnode = malloc(sizeof(struct node));
			start = newnode;
			temp = start;
			printf("\nEnter number to"
				" be inserted : ");
			scanf("%d", &data);
			start->info = data;

			for (int i = 2; i <= n; i++) {
				newnode = malloc(sizeof(struct node));
				temp->link = newnode;
				printf("\nEnter number to"
					" be inserted : ");
				scanf("%d", &data);
				newnode->info = data;
				temp = temp->link;
			}
		}
		printf("\nThe list is created\n");
	}
	else
		printf("\nThe list is already created\n");
}

void traverse()
{
	struct node* temp;

	// List is empty
	if (start == NULL)
		printf("\nList is empty\n");

	// Else print the LL
	else {
		temp = start;
		while (temp != NULL) {
			printf("%d->", temp->info);
			temp = temp->link;
		}
	}
     printf("NULL\n");
}


void insertAtFront()
{
	int data;
	struct node* temp;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to"
		" be inserted : ");
	scanf("%d", &data);
	temp->info = data;

	// Pointer of temp will be
	// assigned to start
	temp->link = start;
	start = temp;
}


void insertAtEnd()
{
	int data;
	struct node *temp, *head;
	temp = malloc(sizeof(struct node));

	// Enter the number
	printf("\nEnter number to"
		" be inserted : ");
	scanf("%d", &data);

	// Changes links
	temp->link = 0;
	temp->info = data;
	head = start;
	while (head->link != NULL) {
		head = head->link;
	}
	head->link = temp;
}


void insertAtPosition()
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = malloc(sizeof(struct node));

	// Enter the position and data
	printf("\nEnter position and data :");
	scanf("%d %d", &pos, &data);

	// Change Links
	temp = start;
	newnode->info = data;
	newnode->link = 0;
	while (i < pos - 1) {
		temp = temp->link;
		i++;
	}
	newnode->link = temp->link;
	temp->link = newnode;
}


void reverseLL()
{
	struct node *t1, *t2, *temp;
	t1 = t2 = NULL;

	// If LL is empty
	if (start == NULL)
		printf("List is empty\n");

	// Else
	else {

		// Traverse the LL
		while (start != NULL) {

			// reversing of points
			t2 = start->link;
			start->link = t1;
			t1 = start;
			start = t2;
		}
		start = t1;

		// New head Node
		temp = start;

		printf("Reversed linked "
			"list is : ");

		// Print the LL
		while (temp != NULL) {
			printf("%d ", temp->info);
			temp = temp->link;
		}
	}
}

// Driver Code
int main()
{
	int choice;
	while (1) {

		printf("1 To see list");
		printf(" 2 For insertion at"
			" starting");
		printf(" 3 For insertion at"
			" end");
		printf(" 4 For insertion at "
			"any position");
		printf(" 5 To reverse the "
			"linked list");
		printf(" 6 To exit");
		printf("\nEnter Choice :");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			reverseLL();
			break;
		case 6:
			exit(1);
			break;
		default:
			printf("Incorrect Choice\n");
		}
	}
	return 0;
}
