#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linklisttraversal(struct Node* ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

// Insert at the beganing
struct Node* insertionAtFirst(struct Node* head , int data){
    struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// insert at btwn
struct Node* insertionAtIndex(struct Node* head , int data,int index){
    struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i=0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// insert at the end;
struct Node* insertionAtEnd(struct Node* head , int data){
    struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
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

    // link 1st and 2nd list
    third->data = 27;
    third->next = NULL;

    linklisttraversal(head);
    // head = insertionAtFirst(head,45);
    // head = insertionAtIndex(head,45,2);
    head = insertionAtEnd(head,45);
    linklisttraversal(head);
    return 0;
}