#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* next;
};

struct node* createNode(int data){
     struct node* new = (struct node*)malloc(sizeof(struct node));
     new->data = data;
     new->next = NULL;
     return new;
}

void display(struct node* head){
     struct node* temp = head;
     while (temp != NULL)
     {
          printf("%d -> ", temp->data);
          temp = temp->next;
     }
}

struct node* create(struct node* head){
     int c = 1;
     int data;
     struct node* temp = NULL;
     while (c)
     {
          printf("Enter data: ");
          scanf("%d",&data);
          struct node* new = createNode(data);
          if(head == NULL){
               head = temp = new;
          }
          else{
               temp->next = new;
               temp = new;
          }
          printf("Do u want to continue? (1/0): ");
          scanf("%d",&c);
     }
     return head;
}

struct node* subLinkedList(struct node* head1, struct node* head2){
     struct node* temp1 = head1;
     struct node* temp2 = head2;
     int h1_data = 0;
     int h2_data = 0;
     while (temp1 != NULL)
     {
          h1_data = h1_data*10 + temp1->data;
          temp1 = temp1->next;
     }
     while (temp2 != NULL)
     {
          h2_data = h2_data*10 + temp2->data;
          temp2 = temp2->next;
     }
     int actual_data = 0;
     if (h1_data>h2_data)
          actual_data = h1_data - h2_data;
     else
          actual_data = h2_data - h1_data;
     struct node* new_head = NULL;
     struct node* new_temp = NULL;
     int len = 0,copy_len = 0;
     int copy_actual_data = actual_data;
     while (copy_actual_data>0)
     {
          len++;
          copy_actual_data/=10;
     }
     copy_actual_data = actual_data;
     // printf("\nThe len is %d\n",len);
     copy_len = len;
     int arr[len];
     while (copy_actual_data>0)
     {
          arr[--len] = copy_actual_data%10;
          copy_actual_data/=10;
     }
     len = copy_len;
     for (int i = 0; i < len; i++)
     {
          struct node* new = createNode(arr[i]);
          if (new_head == NULL)
          {
               new_head = new_temp = new;
          }
          else{
               new_temp->next = new;
               new_temp = new;
          }
     }
     return new_head;
}

int main()
{
     struct node* head1 = NULL;
     head1 = create(head1);
     printf("\nNow Second One.....\n");
     struct node* head2 = NULL;
     head2 = create(head2);
     display(head1);
     printf("\n");
     display(head2);
     struct node* new_head = subLinkedList(head1, head2);
     printf("\nThe New Linked List is :- \n");
     display(new_head);
     printf("NULL\n");
     return 0;
}