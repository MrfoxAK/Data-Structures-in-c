#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

struct node *create_node(int data)
{
     struct node *new_node = (struct node *)malloc(sizeof(struct node));
     new_node->left = NULL;
     new_node->right = NULL;
     new_node->data = data;
     return new_node;
}

struct node* create_tree(){
     struct node* root=NULL;
     int data;
     printf("Enter data: ");
     scanf("%d",&data);
     if (data==-1)
     {
          return 0;
     }
     else{
          root = create_node(data);
          printf("Left node of %d ",data);
          root->left = create_tree();
          printf("right node of %d ",data);
          root->right = create_tree();
     }
     return root;
}

void Postorder_traversal(struct node * root){
     if (root!=NULL)
     {
          Postorder_traversal(root->left);
          Postorder_traversal(root->right);
          printf("%d ",root->data);
     }
}

int main()
{
     struct node* root=NULL;
     root = create_tree();
     Postorder_traversal(root);
     return 0;
}