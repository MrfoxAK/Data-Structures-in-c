#include <stdio.h>
#include <stdlib.h>

struct Node
{
     int val;
     struct Node *link;
};

struct Node* createlinklist(int n){
     struct Node* head=NULL;
     struct Node* p=NULL;
     for (int i = 0; i < n; i++)
     {
          struct Node* newnnode=(struct Node *)malloc(sizeof(struct Node));
          printf("Enter value: ");
          scanf("%d",&newnnode->val);
          newnnode->link=NULL;
          if (head==NULL)
          {
               head=newnnode;
          }
          else
          {
               p=head;
               while (p->link!=NULL)
               {
                    p=p->link;
               }
               p->link=newnnode;
          }
     }
     return head;
}

void display(struct Node* head){
     struct Node*ptr=head;
     while (ptr!=NULL)
     {
          printf("%d->",ptr->val);
          ptr=ptr->link;
     }
}

int main()
{
     int n;
     struct Node*head=NULL;
     printf("How many nodes: ");
     scanf("%d",&n);
     head=createlinklist(n);
     display(head);
}




// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//      int val;
//      struct Node *link;
// };

// void display(struct Node* head){
//      struct Node*ptr=head;
//      while (ptr!=NULL)
//      {
//           printf("%d->",ptr->val);
//           ptr=ptr->link;
//      }
// }

// int main()
// {
//      struct Node *head = NULL;
//      struct Node *second = NULL;
//      struct Node *third = NULL;

//      // allocate 3 nodes in the heap
//      head = (struct Node *)malloc(sizeof(struct Node));
//      second = (struct Node *)malloc(sizeof(struct Node));
//      third = (struct Node *)malloc(sizeof(struct Node));

//      head->val=11;
//      head->link=second;

//      second->val=22;
//      second->link=third;
      
//      third->val=18;
//      third->link=NULL;

//      display(head);
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//      int val;
//      struct node * link;
// };

// int main()
// {
//      struct node* head,*newnode,*temp;
//      head=NULL;
//      int choice;
//      while (choice)
//      {
//           newnode=(struct node*)malloc(sizeof(struct node));
//           printf("Enter the val: ");
//           scanf("%d",&newnode->val);
//           newnode->link=NULL;
//           if (head==NULL)
//           {
//                head=temp=newnode;
//           }
//           else
//           {
//                temp->link=newnode;
//                temp=newnode;
//           }
//           printf("Do you want to continue (1/0) : ");
//           scanf("%d", &choice);
//      }
//      temp = head;
//      while (temp != NULL)
//      {
//           printf("%d -> ", temp->val);
//           temp = temp->link;
//      }
//      return 0;
// }