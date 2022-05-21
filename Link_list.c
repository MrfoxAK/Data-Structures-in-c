// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// void linklisttraversal(struct Node* ptr)
// {
//     while (ptr != NULL)
//     {
//         printf("%d ", ptr->data);
//         ptr = ptr->next;
//     }
// }

// int main()
// {
//     struct Node *head;
//     struct Node *second;
//     struct Node *third;

//     // Allocate memory for nodes in the linked list in heap
//     head = (struct Node *)malloc(sizeof(struct Node));
//     second = (struct Node *)malloc(sizeof(struct Node));
//     third = (struct Node *)malloc(sizeof(struct Node));

//     // link 1st and 2nd list
//     head->data = 7;
//     head->next = second;

//     // link 1st and 2nd list
//     second->data = 17;
//     second->next = third;

//     // link 1st and 2nd list
//     third->data = 27;
//     third->next = NULL;

//     linklisttraversal(head);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

int main()
{
    int choice;
    struct node *head, *newnode, *temp;
    head = NULL;
    while (choice)
    {

        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: \n");
        scanf("%d", &newnode->data);
        newnode->link = NULL;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->link = newnode;
            temp = newnode;
        }
        printf("Do you want to continue: \n");
        scanf("%d",&choice);
    }
    printf("Now printing the data....");
    temp = head;
    int count;
    while (temp!=0)
    {
        printf("\n%d ",temp->data);
        temp = temp->link;
        count++;
    }
    printf("\nThe total no of node is: %d",count);
    return 0;
}
