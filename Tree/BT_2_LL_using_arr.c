#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node * left;
     struct node * right;
};

int arr[100];
int i=0;

struct node* createNode(int data){
     struct node * Node;
     Node = (struct node*)malloc(sizeof(struct node));
     Node->data=data;
     Node->left=NULL;
     Node->right=NULL;
     return Node;
}

void Preorder_traversal(struct node * root){
     if (root!=NULL)
     {
          arr[i]=root->data;
          i++;
          printf("%d ",root->data);
          Preorder_traversal(root->left);
          Preorder_traversal(root->right);
     }
}

struct node* BT_2_LL(){
     struct node * head=NULL;
     struct node * newnode;
     struct node * temp;
     for (int j = 0; j < i; j++)
     {
          newnode=(struct node*)malloc(sizeof(struct node));
          newnode->data=arr[j];
          newnode->right=NULL;
          newnode->left=NULL;
          if (head==NULL)
          {
               head=temp=newnode;
          }
          else
          {
               temp->right=newnode;
               temp=newnode;
          }
     }
     return head;
}

void display(struct node *head)
{
     struct node *p = head;
     while (p != NULL)
     {
          printf("%d->", p->data);
          p = p->right;
     }
     printf("NULL\n");
}

int main()
{
     
     // using function
     struct node * p = createNode(4);
     struct node * p1 = createNode(1);
     struct node * p2 = createNode(6);
     struct node * p3 = createNode(5);
     struct node * p4 = createNode(2);

     p->left=p1;
     p->right=p2;
     p1->left=p3;
     p1->right=p4;

     Preorder_traversal(p);

     printf("\nAfter BT_2_LL\n");
     // head pointer
     struct node * head = NULL;
     head=BT_2_LL();
     // for (int j = 0; j < i; j++)
     // {
     //      printf("%d ",arr[j]);
     // }
     display(head);
     return 0;
}