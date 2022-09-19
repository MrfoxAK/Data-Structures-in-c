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

// // Insert at the beganing
// struct Node* insertionAtFirst(struct Node* head , int data){
//     struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));
//     ptr->data = data;
//     ptr->next = head;
//     return ptr;
// }

// // insert at btwn
// struct Node* insertionAtIndex(struct Node* head , int data,int index){
//     struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));
//     struct Node * p = head;
//     int i=0;
//     while (i!=index-1)
//     {
//         p = p->next;
//         i++;
//     }
//     ptr->data = data;
//     ptr->next = p->next;
//     p->next = ptr;
//     return head;
// }

// // insert at the end;
// struct Node* insertionAtEnd(struct Node* head , int data){
//     struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));
//     struct Node * p = head;
//     while (p->next!=NULL)
//     {
//         p = p->next;
//     }
//     ptr->data = data;
//     p->next = ptr;
//     ptr->next = NULL;
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

//     // link 1st and 2nd list
//     third->data = 27;
//     third->next = NULL;

//     linklisttraversal(head);
//     // head = insertionAtFirst(head,45);
//     // head = insertionAtIndex(head,45,2);
//     head = insertionAtEnd(head,45);
//     linklisttraversal(head);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node* next;
// };

// void linklisttreversal(struct Node * ptr){
//     while (ptr!=NULL)
//     {
//         printf("%d ",ptr->data);
//         ptr=ptr->next;
//     }
// }

// struct Node * insertionAT1st(struct Node * head,int data){
//     struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));
//     Newnode->data = data;
//     Newnode->next = head;
//     return Newnode;
// }

// struct Node * insertionATIndex(struct Node * head,int data,int index){
//     struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));
//     struct Node* ptr = head;
//     int i = 0;
//     while (i!=index-1)
//     {
//         ptr = ptr->next;
//         i++;
//     }
//     Newnode->data = data;
//     Newnode->next = ptr->next;
//     ptr->next = Newnode;
//     return head;
// }

// struct Node * insertionATEnd(struct Node * head,int data){
//     struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));
//     Newnode->data = data;
//     struct Node* ptr = head;
//     while (ptr->next!=NULL)
//     {
//         ptr = ptr->next;
//     }
//     ptr->next = Newnode;
//     Newnode->next = NULL;
//     return head;
// }

// struct Node * insertionAfterNode(struct Node * head,struct Node * PreNode,int data){
//     struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));

//     Newnode->data = data;
//     Newnode->next = PreNode->next;
//     PreNode->next = Newnode;
//     return head;
// }

// int main()
// {
//     struct Node* head;
//     struct Node* sec;
//     struct Node* third;
//     struct Node* fourth;

//     head = (struct Node*)malloc(sizeof(struct Node));
//     sec = (struct Node*)malloc(sizeof(struct Node));
//     third = (struct Node*)malloc(sizeof(struct Node));
//     fourth = (struct Node*)malloc(sizeof(struct Node));

//     head->data = 7;
//     head->next = sec;

//     sec->data=18;
//     sec->next=third;

//     third->data = 22;
//     third->next = fourth;

//     fourth->data = 25;
//     fourth->next = NULL;

//     // linklisttreversal(head);
//     // head = insertionAT1st(head,14);
//     // head = insertionATIndex(head,1,2);
//     // head = insertionATEnd(head,104);
//     head = insertionAfterNode(head,sec,34);
//     linklisttreversal(head);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linklisttreversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->next = head;
    NewNode->data = data;
    return NewNode;
}
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    NewNode->data = data;
    NewNode->next = p->next;
    p->next = NewNode;
    return head;
}
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = data;
    struct Node *p = head;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    p->next = NewNode;
    NewNode->next = NULL;
    return head;
}
struct Node *insertAfterNode(struct Node *head, struct Node *preNode,int data)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->next = preNode->next;
    preNode->next = NewNode;
    return head;
}
int main()
{
    struct Node *head;
    struct Node *sec;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    sec = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = sec;
    sec->data = 18;
    sec->next = third;
    third->data = 22;
    third->next = fourth;
    fourth->data = 25;
    fourth->next = NULL;
    linklisttreversal(head);
    // head = insertAtEnd(head, 15);
    head = insertAfterNode(head,sec,45);
    printf("\n");
    printf("LinkList after insertion.....\n");
    // head = insertAtFirst(head, 15);
    // head = insertAtIndex(head, 15,2);
    linklisttreversal(head);
    return 0;
}