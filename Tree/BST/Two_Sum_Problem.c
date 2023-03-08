#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};

void inOrder_traversal(struct node * root){
     if (root!=NULL)
     {
          inOrder_traversal(root->left);
          printf("%d ",root->data);
          inOrder_traversal(root->right);
     }
}

struct node* createNode(struct node* n,int data){
     n = (struct node*)malloc(sizeof(struct node));
     n->data = data;
     n->left = NULL;
     n->right = NULL;
     return n;
}

struct node * insert(struct node* root,int data){
     if (root==NULL)
     {
          root = createNode(root,data);
     }
     else if (data<root->data)
     {
          root->left = insert(root->left,data);
     }
     else
     {
          root->right = insert(root->right,data);
     }
     return root;
}

int arr[10];

void inOrder(struct node * root){
     static int i=0;
     if (root!=NULL)
     {
          inOrder(root->left);
          // printf("%d ",root->data);
          arr[i] = root->data;
          i++;
          // printf("%d ",i);
          inOrder(root->right);
     }
}

// O(n^2) or O(nlogn)
int Two_sum_prblm(struct node* root,int k){
     inOrder(root);
     for (int i = 0; i < 6; i++)
     {
          if (arr[i]!=0)
          {
               int v=k-arr[i];
               int f=0;
               for (int j = 0; j < 6; j++)
               {
                    if (arr[j]==v)
                    {
                         
                         f=1;
                    }
               }
               if (f==1)
               {
                    return 1;
               }
          }
     }
     return 0;
}

// // O(n)
// bool twoPointers(vector<int> &nodes, int k){
//         // left and right pointer
//         int l = 0, r = nodes.size() - 1;
        
//         while(l < r){
//         int sum = nodes[l] + nodes[r];
//             if(sum == k)return true; //If found valid pair, return true.
//             else if(sum < k) l++;   
//             else if(sum > k) r--;
//         }
//         return false;     // If pair not found, return false.
// }

int main()
{
     struct node* root=NULL;
     root = insert(root,5);
     root = insert(root,6);
     root = insert(root,7);
     root = insert(root,3);
     root = insert(root,2);
     root = insert(root,4);
     // inOrder_traversal(root);
     printf("%d",Two_sum_prblm(root,7));
     return 0;
}