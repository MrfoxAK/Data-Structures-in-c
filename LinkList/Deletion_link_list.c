#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traversal
void linklisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

// case 1 : delete the first node
struct Node *delete1st(struct Node *head)
{
    struct Node*ptr=head;
    head=ptr->next;
    free(ptr);
    return head;
}

// case 2: delete btwn nodes
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node* ptr=head;
    struct Node* p=head->next;
    int i = 0;
    while (i!=index-1)
    {
        ptr=ptr->next;
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    free(p);
    return head;
}

// case 3: delete at the end
struct Node *deleteAtEnd(struct Node *head)
{
    struct Node* p=head->next;
    struct Node* q=head;
    while (p->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    q->next=NULL;
    free(p);
    return head;
}

// case 4: delete at value
struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // link 1st and 2nd list
    head->data = 7;
    head->next = second;

    // link 1st and 2nd list
    second->data = 17;
    second->next = third;
    // free(second);
    // link 1st and 2nd list
    third->data = 27;
    third->next = NULL;

    printf("Linklist before deletion.....\n");
    linklisttraversal(head);

    // head = delete1st(head);
    // head = delete1st(head);
    // head = deleteAtIndex(head,2);
    head = deleteAtValue(head,17);
    // head = deleteAtIndex(head,1);
    printf("Linklist after deletion.....\n");
    linklisttraversal(head);

    return 0;
}




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
//         printf("%d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }

// // case 1 : delete the first node
// struct Node * deleteFirst(struct Node * head){
//     struct Node * p = head;
//     head = head->next;
//     free(p);
//     return head;
// }

// // case 2: delete btwn nodes
// struct Node * deleteAtIndex(struct Node * head, int index){
//     struct Node * p = head;
//     struct Node * q = head->next;
//     for (int i = 0; i < index-1; i++)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     p->next = q->next;
//     free(q);
//     return head;
// }

// // case 3: delete at the end
// struct Node * deleteAtEnd(struct Node * head){
//     struct Node * p = head;
//     struct Node * q = head->next;
//     while(q->next!=NULL)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     p->next = NULL;
//     free(q);
//     return head;
// }

// // case 4: delete at value
// struct Node * deleteAtValue(struct Node * head,int value){
//     struct Node * p = head;
//     struct Node * q = head->next;
//     while(q->data = value && q->next!=NULL)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     if (q->data==value)
//     {
//         p->next = q->next;
//         free(q);
//     }

//     return head;
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
//     // free(second);
//     // link 1st and 2nd list
//     third->data = 27;
//     third->next = NULL;

//     printf("Linklist before deletion.....\n");
//     linklisttraversal(head);

//     // head = deleteFirst(head); for deleting 1st node
//     // head = deleteAtIndex(head,1); for deleting at index
//     // head = deleteAtEnd(head); for delete at end
//     head = deleteAtValue(head,7);
//     printf("Linklist before deletion.....\n");
//     linklisttraversal(head);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// // Traversal
// void linklisttraversal(struct Node *ptr)
// {
//     while (ptr != NULL)
//     {
//         printf("%d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }

// // case 1 : delete the first node
// struct Node *delete1st(struct Node *head)
// {
//     struct Node *ptr = head;
//     head = head->next;
//     free(ptr);
//     return head;
// }

// // case 2: delete btwn nodes
// struct Node *deleteAtIndex(struct Node *head, int index)
// {
//     struct Node *p = head;
//     struct Node *q = head->next;
//     for (int i = 0; i < index - 1; i++)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     p->next = q->next;
//     free(q);
//     return head;
// }

// // case 3: delete at the end
// struct Node *deleteAtEnd(struct Node *head)
// {
//     struct Node *p = head;
//     struct Node *q = head->next;
//     while (q->next != NULL)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     p->next = NULL;
//     free(q);
//     return head;
// }

// // case 4: delete at value
// struct Node *deleteAtValue(struct Node *head, int value)
// {
//     struct Node *p = head;
//     struct Node *q = head->next;
//     while (q->data != value && q->next != NULL)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     if (q->data == value)
//     {
//         p->next = q->next;
//         free(q);
//     }
//     return head;
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
//     // free(second);
//     // link 1st and 2nd list
//     third->data = 27;
//     third->next = NULL;

//     printf("Linklist before deletion.....\n");
//     linklisttraversal(head);

//     // head = delete1st(head);
//     // head = delete1st(head);
//     // head = deleteAtIndex(head,2);
//     // head = deleteAtEnd(head);
//     head = deleteAtValue(head, 17);
//     printf("Linklist before deletion.....\n");
//     linklisttraversal(head);

//     return 0;
// }